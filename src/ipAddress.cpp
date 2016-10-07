/* $Id$
 * $Version: 0.8$
 * $Revision: 12$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "CipAddress.h"
#include "Cipv4Address.h"

CipAddress::CipAddress() { /* empty */ }

CipAddress::~CipAddress() { /* empty */ }


Cipv4Address::Cipv4Address()
{
    // TODO
}

Cipv4Address::~Cipv4Address()
{
    // TODO
}

/**
 * @param string
 * @return char[]
 */
char* 
Cipv4Address::convFromStr(std::string s)
{
    // TODO
    return nullptr;
}

/**
 * @param char[4]
 * @return string
 */
std::string
Cipv4Address::convToStr(char* s)
{
    // TODO
    return "";
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
