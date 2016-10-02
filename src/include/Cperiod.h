/* $Id$
 * $Version: 7.4.0$
 * $Revision: 14$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CPERIOD_H
#define _CPERIOD_H

#include "InterMon.h"
#include "Cbasic.h"
#include "period_t.h"

class Cperiod: public Cbasic {
public: 
    /* */
    Cperiod();
    /* */
    ~Cperiod();
protected:
    period_t _period;
};

#endif //_CPERIOD_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
