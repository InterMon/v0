/* $Id$
 * $Version: 0.6$
 */
/**
 * Project InterMon v0.6
 */

#include "CmainServer.h"

const std::string localhost = "127.0.0.1";
const std::string defaultConfigFile = "/usr/local/etc/intermon/intermon.conf";

CmainServer::CmainServer()
: conf(defaultConfigFile), ipAddress(localhost)
{ }

CmainServer::~CmainServer() { }

typedef std::vector<std::string>::const_iterator cInter;

void CmainServer::init() {
    const std::vector<std::string> c = conf.config();
    for (cInter i = c.begin(); i != c.end(); ++i) {
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

void CmainServer::run() {

}

void CmainServer::eventLoop() {

}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
