/* $Id$
 * $Version: 0.7$
 */
/**
 * Project InterMon v0.7
 */

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
    std::vector<std::string> persons;
};

#endif //_CCONTACTGROUP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
