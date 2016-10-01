/* $Id$
 * $Version: 7.3.0$
 * $Revision: 11$
 */
/**
 * Project InterMon v0.7.3
 */

#pragma once
#ifndef _CIPV4ADDRESS_H
#define _CIPV4ADDRESS_H

#include "InterMon.h"
#include "CipAddress.h"


class Cipv4Address: public CipAddress {
public: 
    /* */
    Cipv4Address();
    /* */
    ~Cipv4Address();
    /* */
    /**
     * @param string
     */
    char* convFromStr(std::string);
    /* */
    /**
     * @param char[4]
     */
    std::string convToStr(char*);
protected: 
    char octets[4];
};

#endif //_CIPV4ADDRESS_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
