/* $Id$
 * $Version: 0.8$
 * $Revision: 19$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CID_H
#define _CID_H

#include "Cbasic.h"

class Cid: public Cbasic {
    static long long seq;
    Cid(long long i) : id(i) { /* Empty */ }
public:
    const long long id;
    Cid();
    Cid(const Cid & other);
    Cid & operator=(const Cid & other);
    Cid(const Cid && other);
    Cid & operator=(const Cid && right);

    /**
     * Destructor
     */
    ~Cid();
protected:
    void move(const Cid && right);
};

#endif //_CID_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
