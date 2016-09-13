/* $Id$
 * $Version: 0.7$
 */
/**
 * Project InterMon v0.7
 */

extern "C" {
#include "cpue.h"
}
#include "CmainServer.h"

typedef std::vector<Chost>::const_iterator hIter;
typedef std::vector<std::string>::const_iterator cIter;
typedef std::vector<std::thread*>::iterator tIter;

const std::string localhost = "127.0.0.1";
const std::string defaultConfigFile = "/usr/local/etc/intermon/intermon.conf";

CmainServer::CmainServer()
: conf(defaultConfigFile), ipAddress(localhost)
{ /* empty */ }

CmainServer::~CmainServer() {
    for (tIter i = _threads.begin(); i != _threads.end(); ++i) {
        delete *i;
    }
}

void CmainServer::init() {
    const std::vector<std::string> c = conf.config();
    for (cIter i = c.begin(); i != c.end(); ++i) {
        if (*i == "host") {
            i++;
            if (i != c.end()) {
                hosts.push_back(*i);
            } else {
                std::cerr << "Syntax error!" << std::endl;
            }
        }
    }
}

void CmainServer::readConf() {
    // TODO
}

void eventLoop0(Chost host) {
    while (true) {
        host.checkCommand();
        myusleep(host.getCheckInterval()*1000000);
    }
}

void CmainServer::run() {
    for (hIter i = hosts.begin(); i != hosts.end(); ++i) {
        _threads.push_back(new std::thread(eventLoop0, *i));
    }
    while (true) {
        myusleep(1000);
        // TODO
    }
}

void CmainServer::eventLoop(Chost & host) {
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
