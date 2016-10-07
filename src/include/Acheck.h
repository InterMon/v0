/* $Id$
 * $Version: 0.8$
 * $Revision: 16$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CCHECK_H
#define _CCHECK_H

#include "Cbasic.h"
#include "Cperiod.h"

class Acheck: public Cbasic {
public:
    Acheck() { /* Empty */ }
    virtual ~Acheck() { /* Empty */ }
    virtual void checkCommand() = 0;
    virtual int getCheckInterval() { return _normalCheckInterval; }
protected:
    int     _state = 0;
    Cperiod _checkPeriod;
    int     _normalCheckInterval = 5;
    int     _maxCheckAttempts = 2;
    int     _retryInterval = 2;
};

#endif //_CCHECK_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
