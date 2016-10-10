/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 23$
=======
 * $Revision: 21$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
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
#include "Sname.h"
#include "Chost.h"
#include "Cpool.h"

#define MY_CPU_COUNT 2
<<<<<<< HEAD
#define __TEST_DEVELOPING__ true
=======
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4

class CmainServer: public Sname {
public: 
    /* */
    CmainServer();
    /* */
    CmainServer(const std::string & configFile);

    /* */
    void init();
    /* */
    void readConf() { _conf.parse(_hosts); }
    /* */
    void run();
    /* */
    void eventLoop(Chost & host);

    /**
     * Destructor
     */
    ~CmainServer();
private:
    Cconfiguration            _conf;
    std::string               _ipAddress;
    std::vector<Chost*>       _hosts;
    std::vector<Cpool>        _pools;
    friend void eventLoop0(Chost *);
};

#endif //_CMAINSERVER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
