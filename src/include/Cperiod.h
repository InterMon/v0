/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 18$
=======
 * $Revision: 17$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CPERIOD_H
#define _CPERIOD_H

#include "Cbasic.h"
#include "period_t.h"

class Cperiod: public Cbasic {
public:
    /* */
    Cperiod();

    /**
     * Destructor
     */
    ~Cperiod();
protected:
    period_t _period;
};

#endif //_CPERIOD_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
