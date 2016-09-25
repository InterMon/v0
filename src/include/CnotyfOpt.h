/* $Id$
 * $Version: 7.3.0$
 * $Revision: 8$
 */
/**
 * Project InterMon v0.7.3
 */

#ifndef _CNOTYFOPT_H
#define _CNOTYFOPT_H

#include "InterMon.h"
#include "Cbasic.h"
#include "notify_t.h"

class CnotyfOpt: public Cbasic {
public: 
    /* */
    CnotyfOpt();
    /* */
    ~CnotyfOpt();
private: 
    notify_t opt;
};

#endif //_CNOTYFOPT_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
