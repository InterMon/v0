/* $Id$
 * $Version: 0.8$
 * $Revision: 21$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CCONTACTGROUP_H
#define _CCONTACTGROUP_H

#include <string>
#include <vector>
#include "Sname.h"

class CcontactGroup: private Sname {
private:
    std::vector<std::string> _persons;
public:
    /* */
    CcontactGroup();

    /* */
    void notifyMethod();

    /**
     * Empty Destructor
     */
    ~CcontactGroup();
};

#endif //_CCONTACTGROUP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
