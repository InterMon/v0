/* $Id$
 * $Version: 0.6$
 */
/**
 * Project InterMon v0.6
 */


#ifndef _CMAINSERVER_H
#define _CMAINSERVER_H

#include "InterMon.h"
#include "Cconfiguration.h"
#include "Cname.h"
#include "Chost.h"

class CmainServer: public Cname {
public: 
    /* */
    CmainServer();
    explicit CmainServer(const char ** c)
    : conf(c)
    { }
    /* */
    ~CmainServer();
    /* */
    void init();
    /* */
    void readConf();
    /* */
    void run();
    /* */
    void eventLoop();
private: 
    Cconfiguration conf;
    std::string ipAddress;
    std::vector<Chost> hosts;
};

#endif //_CMAINSERVER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
