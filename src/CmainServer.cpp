/* $Id$
 * $Version: 0.7.2$
 * $Revision: 11$
 */
/**
 * Project InterMon v0.7.2
 */

extern "C" {
#include "cpue.h"
}
#include "Cdb.h"
#include "CmainServer.h"
#include "Cconfiguration.h"

using namespace std;

typedef vector<Chost*>::iterator hIter;
typedef vector<string>::const_iterator cIter;
typedef vector<thread*>::iterator tIter;

const string localhost = "127.0.0.1";
const string defaultConfigFile = "intermon.conf.xml";

CmainServer::CmainServer()
: conf(defaultConfigFile), ipAddress(localhost)
{ /* empty */ }

CmainServer::CmainServer(const std::string & configFile)
: conf(configFile), ipAddress(localhost)
{ /* empty */ }

CmainServer::~CmainServer() {
    for (tIter i = _threads.begin(); i != _threads.end(); ++i) {
        delete *i;
    }
    for (hIter i = hosts.begin(); i != hosts.end(); ++i) {
        delete *i;
    }
}

void CmainServer::init() {
    readConf();
    const vector<string> c = conf.config();
    for (cIter i = c.begin(); i != c.end(); ++i) {
        if (*i == "host") {
            i++;
            if (i != c.end()) {
                hosts.push_back(new Chost(*i));
                mdb.addHost(*i);
            } else {
                cerr << "Syntax error!" << endl;
            }
        }
    }
    for (size_t i = 0; i < hosts.size(); ++i) {
        cerr << "Hostname: "
             << hosts[i]->getHostname()
             << "&host[" << i << "]: "
             << &hosts[i]
             << endl;
    }
}

void eventLoop0(Chost * host) {
    while (true) {
        const string & hostName = host->getHostname();
        mdb.setHostStatus(hostName, 1);
        myusleep(host->getCheckInterval()*1000000/2);
        cerr << "setHostStatus("
             << hostName << ", "
             << mdb.getHostStatus(hostName)
             << ")" << endl;
        host->checkCommand();
        myusleep(host->getCheckInterval()*MYUSLEEP_1SEC/2);
        cerr << "getHostStatus("
             << hostName << ") => "
             << mdb.getHostStatus(hostName)
             << endl;
    }
}

void CmainServer::run() {
    for (hIter i = hosts.begin(); i != hosts.end(); ++i) {
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
        printd("mdb.") << endl;
#endif
        try { 
            mdb.backup(); 
        } catch (std::runtime_error& e) {
            cerr << e.what() << endl;
#if defined(DEBUG) && defined(PRINTM)
            printd("Error: ", e.what()) << endl;
#endif
        }
    }
}

void CmainServer::eventLoop(Chost & host) {
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
