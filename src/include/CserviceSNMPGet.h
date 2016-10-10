/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 16$
=======
 * $Revision: 15$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
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
    void checkCommand();

    /* */
    void notifyCommand();

    /* */
    Acommand * getCheckCommand() throw(std::bad_alloc);

    /**
     * Destructor
     */
    ~CserviceSNMPGet();
protected:
    std::string _community;
};

#endif //_CSERVICESNMPGET_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
