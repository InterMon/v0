/* $Id$
 * $Version: 7.3.0$
 * $Revision: 9$
 */
/**
 * Project InterMon v0.7.3
 */

#pragma once
#ifndef _CSERVICESNMPGET_H
#define _CSERVICESNMPGET_H

#include "InterMon.h"
#include "Aservice.h"


class CserviceSNMPGet: public Aservice {
public: 
    /* */
    CserviceSNMPGet();
    /* */
    ~CserviceSNMPGet();
    /* */
    void checkCommand();
    /* */
    void notifyCommand();
protected: 
    std::string community;
};

#endif //_CSERVICESNMPGET_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
