/* $Id$
 * $Version: 7.3.0$
 * $Revision: 8$
 */
/**
 * Project InterMon v0.7.3
 */


#ifndef _CMAINSERVER_H
#define _CMAINSERVER_H

#include "InterMon.h"
#include "Cconfiguration.h"
#include "Cname.h"
#include "Chost.h"
#include <thread>

class CmainServer: public Cname {
public: 
    /* */
    CmainServer();
    /* */
    CmainServer(const std::string & configFile);
    /* */
    explicit CmainServer(const char ** c)
    : conf(c) { /* empty*/ }
    /* */
    ~CmainServer();
    /* */
    void init();
    /* */
    void readConf() { conf.parse(); }
    /* */
    void run();
    /* */
    void eventLoop(Chost & host);
private: 
    Cconfiguration conf;
    std::string ipAddress;
    std::vector<Chost*> hosts;
    std::vector<std::thread*> _threads;
    friend void eventLoop0(Chost *);
};

#endif //_CMAINSERVER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
