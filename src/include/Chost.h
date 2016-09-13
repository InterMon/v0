/* $Id$
 * $Version: 0.7$
 * $Revision: 6$
 */
/**
 * Project InterMon v0.7
 */

#ifndef _CHOST_H
#define _CHOST_H

#include "InterMon.h"
#include "Cname.h"
#include "Ccheck.h"
#include "CipAddress.h"
#include "Cipv4Address.h"
#include "Cnotification.h"
#include "Cservice.h"

class Chost: public Ccheck, public Cnotification {
public: 
    /* */
    Chost();
    Chost(const std::string name)
    : hostName(name) { /* empty */ }
    /* */
    ~Chost();
    /* */
    void checkCommand();
    /* */
    void checkServices();
    /* */
    void notifyCommand();
private: 
    std::string hostName;
    CipAddress ipAddress;
    std::vector<Cservice> services;
};

#endif //_CHOST_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
