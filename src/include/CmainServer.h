/* $Id$
 * $Version: 0.8$
 * $Revision: 15$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CMAINSERVER_H
#define _CMAINSERVER_H

#include <string>
#include <thread>
#include "Cconfiguration.h"
#include "Cname.h"
#include "Chost.h"

class CmainServer: public Cname {
public: 
    /* */
    CmainServer();
    /* */
    CmainServer(const std::string & configFile);
    /* */
    ~CmainServer();
    /* */
    void init();
    /* */
    void readConf() { _conf.parse(_hosts); }
    /* */
    void run();
    /* */
    void eventLoop(Chost & host);
private: 
    Cconfiguration            _conf;
    std::string               _ipAddress;
    std::vector<Chost*>       _hosts;
    std::vector<std::thread*> _threads;
    friend void eventLoop0(Chost *);
};

#endif //_CMAINSERVER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
