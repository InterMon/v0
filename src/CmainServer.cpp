/* $Id$
 * $Version: 0.8$
 * $Revision: 19$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include <iostream>
#include <string>
#include <vector>
extern "C" {
#include "cpue.h"
}
#include "Cdb.h"
#include "Acommand.h"
#include "Ccommand.h"
#include "CmainServer.h"
#include "strs.h"

using namespace std;

typedef vector<Chost*>::iterator hIter;
typedef vector<string>::const_iterator cIter;
typedef vector<thread*>::iterator tIter;

CmainServer::CmainServer()
: _conf(defaultConfigFile), _ipAddress(localhost)
{ /* empty */ }

CmainServer::CmainServer(const std::string & configFile)
: _conf(configFile), _ipAddress(localhost)
{ /* empty */ }

CmainServer::~CmainServer()
{
    for (tIter i = _threads.begin(); i != _threads.end(); ++i) {
        delete *i;
    }
    for (hIter i = _hosts.begin(); i != _hosts.end(); ++i) {
        delete *i;
    }
}

void
CmainServer::init()
{
    readConf();
    for (size_t i = 0; i < _hosts.size(); ++i) {
        cerr << "Hostname: "
             << _hosts[i]->getHostname()
             << "&_host[" << i << "]: "
             << &_hosts[i]
             << endl;
        Chost * host = _hosts[i];
        cerr << "cmd done" << endl;
    }
}

void
eventLoop0(Chost * host)
{
    Acommand * cmd = new Ccommand<Chost>(host, &Chost::checkCommand);
    while (true) {
        const string & hostName = host->getHostname();
        mdb.setHostStatus(hostName, 1);
        myusleep(host->getCheckInterval()*MYUSLEEP_1SEC/2);
        cerr << "setHostStatus("
             << hostName << ", "
             << mdb.getHostStatus(hostName)
             << ")" << endl;
        cmd->execute();
        myusleep(host->getCheckInterval()*MYUSLEEP_1SEC/2);
        cerr << "getHostStatus("
             << hostName << ") => "
             << mdb.getHostStatus(hostName)
             << endl;
    }
    delete cmd;
}

void
eventLoop1(Chost * host)
{
    while (true) {
    }
}

void
CmainServer::run()
{
    for (hIter i = _hosts.begin(); i != _hosts.end(); ++i) {
        Chost * host = *i;
        _threads.push_back(new thread(eventLoop0, host));
        myusleep(MYUSLEEP_1SEC/2);
    }
    while (true) {
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
    }
}

void
CmainServer::eventLoop(Chost & host)
{
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
