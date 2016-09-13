/* $Id$
 * $Version: 0.6$
 */
/**
 * Project InterMon v0.6
 */


#ifndef _CCHECK_H
#define _CCHECK_H

#include "InterMon.h"
#include "Cbasic.h"
#include "Cperiod.h"

class Ccheck: public Cbasic {
public:
    Ccheck();
    virtual ~Ccheck() = 0;
    virtual void checkCommand() = 0;
protected:
    int state;
    Cperiod checkPeriod;
    int normalCheckInterval;
    int maxCheckAttempts;
    int retryInterval;
};

#endif //_CCHECK_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
