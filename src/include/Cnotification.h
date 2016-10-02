/* $Id$
 * $Version: 7.4.0$
 * $Revision: 14$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CNOTIFICATION_H
#define _CNOTIFICATION_H

#include "InterMon.h"
#include "Cname.h"
#include "Cbasic.h"
#include "Cperiod.h"
#include "CnotyfOpt.h"
#include "CcontactGroup.h"

class Cnotification: public Cbasic {
public: 
    /* */
    Cnotification();
    /* */
    virtual ~Cnotification();
    /* */
    virtual void notifyCommand() = 0;
protected: 
    Cperiod                    _notificationPeriod;
    int                        _notificationInterval = 30;
    CnotyfOpt                  _notificationOptions;
    std::vector<CcontactGroup> _contactGroups;
};

#endif //_CNOTIFICATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
