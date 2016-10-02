/* $Id$
 * $Version: 7.4.0$
 * $Revision: 14$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CCONFIGURATION_H
#define _CCONFIGURATION_H

#include "InterMon.h"
#include "Cname.h"
#include "Cbuilder.h"
#include "tinyxml.h"
#include <fstream>      // std::ifstream

extern const std::string devNull;

class Cconfiguration: public Cname {
public:
    Cconfiguration(const std::string & s = devNull);
    ~Cconfiguration();
    int parse(std::vector<Chost*> & hosts);
private:
    TiXmlDocument _cfgxml;
};

#endif //_CCONFIGURATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
