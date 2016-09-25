/* $Id$
 * $Version: 7.3.0$
 * $Revision: 8$
 */
/**
 * Project InterMon v0.7.3
 */

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
    Cperiod notificationPeriod;
    int notificationInterval = 30;
    CnotyfOpt notificationOptions;
    std::vector<CcontactGroup> contactGroups;
};

#endif //_CNOTIFICATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
