/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 21$
=======
 * $Revision: 20$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CCHECK_H
#define _CCHECK_H

#include "Cbasic.h"
#include "Cperiod.h"

/**
  * class Acheck
  * title Abstract check
  * goals Describe interface
  */

class Acheck: public Cbasic {
protected:
    int     _state = 0;
    Cperiod _checkPeriod;
    int     _normalCheckInterval = 5;
    int     _maxCheckAttempts = 2;
    int     _retryInterval = 2;
public:
    /**
     * Empty Constructor
     */
    Acheck() { /* Empty */ }

    /**
     * Method of interface use for check a commad.
     */
    virtual void checkCommand() = 0;

    /**
     * Method of interface return normal check interval in minutes.
     * @return int
     */
    virtual int getCheckInterval() { return _normalCheckInterval; }

    /**
     * Empty Destructor
     */
    virtual ~Acheck() { /* Empty */ }
};

#endif //_CCHECK_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
