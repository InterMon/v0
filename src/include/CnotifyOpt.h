/* $Id$
 * $Version: 0.8$
 * $Revision: 17$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CNOTYFOPT_H
#define _CNOTYFOPT_H

#include "Cbasic.h"
#include "notify_t.h"

class CnotyfOpt: public Cbasic {
public:
    /* */
    CnotyfOpt();

    /**
     * Destructor
     */
    ~CnotyfOpt();
private:
    notify_t _opt;
};

#endif //_CNOTYFOPT_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
