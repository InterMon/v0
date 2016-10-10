/* $Id$
 * $Version: 0.8$
 * $Revision: 26$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
extern "C" {
#include "cpue.h"
}
#include "Cdb.h"
#include "Acommand.h"
#include "Ccommand.h"
#include "Cjob.h"
#include "Cpool.h"
#include "CmainServer.h"
#include "InterMon.h"
#include "strs.h"

using namespace std;

typedef vector<Chost*>::iterator hIter;
typedef vector<Cpool>::iterator pIter;

CmainServer::CmainServer()
: _conf(defaultConfigFile), _ipAddress(localhost)
{ /* empty */ }

CmainServer::CmainServer(const std::string & configFile)
: _conf(configFile), _ipAddress(localhost)
{ /* empty */ }

CmainServer::~CmainServer()
{
    for (pIter itr = _pools.begin(); itr != _pools.end(); ++itr) {
        Cpool & pool = *itr;
        pool.~Cpool();
    }
    for (hIter itr = _hosts.begin(); itr != _hosts.end(); ++itr) {
        Chost * ptrHost = *itr;
        delete ptrHost;
    }
}

void
CmainServer::init()
{
    readConf();
}

void
eventLoop0(Chost * host)
{
    while (true) {
        const string & hostName = host->getHostname();
        mdb.setHostStatus(hostName, 1);
        myusleep(host->getCheckInterval()*MYUSLEEP_1SEC/2);
        cerr << "setHostStatus("
             << hostName << ", "
             << mdb.getHostStatus(hostName)
             << ")" << endl;
        // cmd->execute();
        myusleep(host->getCheckInterval()*MYUSLEEP_1SEC/2);
        cerr << "getHostStatus("
             << hostName << ") => "
             << mdb.getHostStatus(hostName)
             << endl;
    }
}

void
eventLoop1(Cpool * pool)
{
#if defined(__TEST_DEVELOPING__)
    int testCount = 9;
#endif
    myusleep(2*MYUSLEEP_1SEC);
    while (not pool->isJobsEmpty()) {
        cout << "top" << endl;
        const Cjob & jobTop = pool->topOfJobs();
        cout << "jobTop.service() = " << jobTop.service()
            << " jobTop.command() = " << jobTop.command() << endl;
        if (!jobTop.isServiceNull() and !jobTop.isCommandNull()) {
            std::cout << "Q.top: jobTop.name = " << jobTop.name
                      <<       " jobTop.id = " << jobTop.id << std::endl;
            cout << "pop" << endl;
            Cjob job = std::move(pool->popJob());
#if defined(__TEST_DEVELOPING__)
            if (0 < testCount) {
                cout << "push " << testCount << endl;
                pool->pushJob(std::move(job));
                testCount--;
            }
#endif
        }
        myusleep(2*MYUSLEEP_1SEC/3);
        cout << boolalpha;
        cout << "pool->isJobsEmpty(): " << pool->isJobsEmpty() << endl;
    }
}

void
CmainServer::run()
{
    for (hIter i = _hosts.begin(); i != _hosts.end(); ++i) {
        Chost * host = *i;
        myusleep(MYUSLEEP_1SEC/2);
        cout << "hostname: " << host->getHostname() << endl;
        Chost::CservicesIterator services = host->getServicesIterator();
        while (services.hasNext()) {
            Aservice * service = services.next();
            cout << " servicename: " << service->getDescription() << endl;
        }
    }
    for (int i = 0; i < MY_CPU_COUNT; ++i) {
        Cpool pool;
        pool.name = std::string("Pool N ") + std::to_string(i);
        _pools.push_back(std::move(pool));
    }
    int i = 0;
    for (hIter itr = _hosts.begin(); itr != _hosts.end(); ++itr, ++i) {
        Chost * host = *itr;
        Cpool & pool = _pools[i % MY_CPU_COUNT];
        pool.addHost(host);
        cout << "hostname: " << host->getHostname()
             << " added to " << pool.name
             << endl;
        Chost::CcommandsIterator commands = host->getCommandsIterator();
        while (commands.hasNext()) {
            Acommand * command = commands.next();
            Aservice * service = command->getReceiver();
            cout << " command of service: " << service->getDescription()
                 << " added to " << pool.name
                 << endl;
                Cjob job(service, command);
                job.name = service->getDescription();
                pool.pushJob(std::move(job));
        }
    }
    myusleep(MYUSLEEP_1SEC/2);
    for (pIter itr = _pools.begin(); itr != _pools.end(); ++itr) {
        Cpool & pool = *itr;
        pool.newThread(new thread(eventLoop1, &pool));
        myusleep(3*MYUSLEEP_1SEC/4);
    }
    bool isAllPollsEmpry = false;
    while (not isAllPollsEmpry) {
#if defined(DEBUG) && defined(PRINTM)
        printd("run sleep!") << endl;
#endif
        myusleep(MYUSLEEP_3SEC);
#if defined(DEBUG) && defined(PRINTM)
        printd("mdb.backup(): ");
#endif
        try {
            mdb.backup();
        } catch (std::runtime_error & e) {
            cerr << e.what() << endl;
#if defined(DEBUG) && defined(PRINTM)
            printd("Error: ", e.what()) << endl;
#endif
        }
        myusleep(6*MYUSLEEP_1SEC);
        isAllPollsEmpry = true;
        for (pIter itr = _pools.begin(); itr != _pools.end(); ++itr) {
           Cpool & pool = *itr;
           isAllPollsEmpry = isAllPollsEmpry && pool.isJobsEmpty();
        }
    }
    for (pIter itr = _pools.begin(); itr != _pools.end(); ++itr) {
        Cpool & pool = *itr;
        pool.threadJoin();
    }
}

void
CmainServer::eventLoop(Chost & host)
{
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
