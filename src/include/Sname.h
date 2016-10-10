/* $Id$
 * $Version: 0.8$
 * $Revision: 21$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CNAME_H
#define _CNAME_H

#include <string>
#include <iostream>
#include "Cid.h"

struct Sname: public Cid {
    std::string name;
    Sname();
    Sname(const Sname & other);
    Sname & operator=(const Sname & right);
    Sname(const Sname && other);
    Sname & operator=(const Sname && right);

    /**
     * Destructor
     */
    ~Sname() { /* Empty */ }
};

#endif //_CNAME_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
