/* $Id$
 * $Version: 7.3.0$
 * $Revision: 9$
 */
/**
 * Project InterMon v0.7.3
 */


#ifndef _CCHECK_H
#define _CCHECK_H

#include "InterMon.h"
#include "Cbasic.h"
#include "Cperiod.h"

class Ccheck: public Cbasic {
public:
    Ccheck() { /* Empty */ }
    virtual ~Ccheck() { /* Empty */ }
    virtual void checkCommand() = 0;
    virtual int getCheckInterval() { return normalCheckInterval; }
protected:
    int state = 0;
    Cperiod checkPeriod;
    int normalCheckInterval = 5;
    int maxCheckAttempts = 2;
    int retryInterval = 2;
};

#endif //_CCHECK_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
