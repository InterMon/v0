/* $Id$
 * $Version: 7.4.0$
 * $Revision: 14$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CCONTACTGROUP_H
#define _CCONTACTGROUP_H

#include "InterMon.h"
#include "Cname.h"

class CcontactGroup: private Cname {
public: 
    /* */
    CcontactGroup();
    /* */
    ~CcontactGroup();
    /* */
    void notifyMethod();
private:
    std::vector<std::string> _persons;
};

#endif //_CCONTACTGROUP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
