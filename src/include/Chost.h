/* $Id$
 * $Version: 7.3.0$
 * $Revision: 12$
 */
/**
 * Project InterMon v0.7.3
 */

#pragma once
#ifndef _CHOST_H
#define _CHOST_H

#include "InterMon.h"
#include "Cname.h"
#include "Acheck.h"
#include "Cdb.h"
#include "CipAddress.h"
#include "Cipv4Address.h"
#include "Cnotification.h"
#include "Aservice.h"

class Chost: public Acheck, public Cnotification {
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
    /* */
    const std::string & getHostname() { return hostName; };
    void addService(Aservice * service);
private: 
    std::string hostName;
    CipAddress ipAddress;
    std::vector<Aservice*> services;
};

#endif //_CHOST_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
