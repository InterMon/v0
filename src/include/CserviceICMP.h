/* $Id$
 * $Version: 7.4.0$
 * $Revision: 12$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CSERVICEICMP_H
#define _CSERVICEICMP_H

#include "InterMon.h"
#include "Aservice.h"
#include "Acommand.h"
#include "Ccommand.h"

/**
  * class CserviceICMP 
  */
class CserviceICMP: public Aservice {
public: 
    /* */
    CserviceICMP();
    /* */
    ~CserviceICMP();
    /* */
    void checkCommand();
    /* */
    void notifyCommand();
    /* */
    void Action();
private: 
    int _icmpType;
};

#endif //_CSERVICEICMP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
