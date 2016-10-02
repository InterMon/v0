/* $Id$
 * $Version: 7.4.0$
 * $Revision: 16$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CSERVICE_H
#define _CSERVICE_H

#include "InterMon.h"
#include "Acheck.h"
#include "Cnotification.h"

class Aservice: public Acheck, public Cnotification {
public: 
    /* */
    Aservice() { /* empty */ };
    /* */
    virtual ~Aservice() { /* empty */ };
    /* */
    virtual void checkCommand() = 0;
    /* */
    virtual void notifyCommand() = 0;
protected: 
    std::string _description;
};

#endif //_CSERVICE_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
