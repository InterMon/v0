/* $Id$
 * $Version: 0.8$
 * $Revision: 18$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CIPV4ADDRESS_H
#define _CIPV4ADDRESS_H

#include <string>
#include "CipAddress.h"

class Cipv4Address: public CipAddress {
public: 
    /* */
    Cipv4Address();

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

    /**
     * Empty Destructor
     */
    ~Cipv4Address();
protected:
    char _octets[4];
};

#endif //_CIPV4ADDRESS_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
