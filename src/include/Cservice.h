/* $Id$
 * $Version: 0.7$
 */
/**
 * Project InterMon v0.7
 */

#ifndef _CSERVICE_H
#define _CSERVICE_H

#include "InterMon.h"
#include "Cname.h"
#include "Ccheck.h"
#include "Cnotification.h"

class Cservice: public Ccheck, public Cnotification {
public: 
    /* */
    Cservice();
    /* */
    virtual ~Cservice();
    /* */
    virtual void checkCommand() { /* empty */ };
    /* */
    virtual void notifyCommand() { /* empty */ };
protected: 
    std::string description;
};

#endif //_CSERVICE_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
