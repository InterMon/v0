/* $Id$
 * $Version: 0.8$
 * $Revision: 16$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CHOST_H
#define _CHOST_H

#include <queue>
#include <string>
#include "Acheck.h"
#include "CipAddress.h"
#include "Cnotification.h"
#include "Aservice.h"
#include "Acommand.h"
#include "Ccommand.h"

class Chost: public Acheck, public Cnotification {
public: 
    Chost() = default;
    Chost(const std::string name)
    : _hostName(name) { /* empty */ }
    /* */
    ~Chost();
    /* */
    void checkCommand();
    /* */
    void checkServices();
    /* */
    void notifyCommand();
    /* */
    const std::string & getHostname() { return _hostName; };
    /* */
    void addService(Aservice * service);
    /* */
    void AddCommand(Acommand * command);
private: 
    std::string                    _hostName;
    CipAddress                     _ipAddress;
    std::vector<Aservice*>         _services;
};

#endif //_CHOST_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
