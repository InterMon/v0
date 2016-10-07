/* $Id$
 * $Version: 0.8$
 * $Revision: 13$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CSERVICESNMPGET_H
#define _CSERVICESNMPGET_H

#include <string>
#include <stdexcept>
#include "Aservice.h"
#include "Acommand.h"

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
    /* */
    Acommand * getCheckCommand() throw(std::bad_alloc);
protected:
    std::string _community;
};

#endif //_CSERVICESNMPGET_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
