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
#ifndef _CNOTIFICATION_H
#define _CNOTIFICATION_H

#include <vector>
#include "Cbasic.h"
#include "Cperiod.h"
#include "CnotifyOpt.h"
#include "CcontactGroup.h"

class Cnotification: public Cbasic {
public:
    /* */
    Cnotification();
    /* */
    virtual void notifyCommand() = 0;

    /**
     * Destructor
     */
    ~Cnotification();
protected:
    Cperiod                    _notificationPeriod;
    int                        _notificationInterval = 30;
    CnotyfOpt                  _notificationOptions;
    std::vector<CcontactGroup> _contactGroups;
};

#endif //_CNOTIFICATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
