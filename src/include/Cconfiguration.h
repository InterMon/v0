/* $Id$
 * $Version: 0.5$
 */
/**
 * Project InterMon v0.5
 */

#ifndef _CCONFIGURATION_H
#define _CCONFIGURATION_H

#include "InterMon.h"
#include "Cname.h"
#include <fstream>      // std::ifstream

class Cconfiguration: public Cname {
public:
    Cconfiguration(std::string);
    ~Cconfiguration();
    int parse();
private:
    std::ifstream inFile;
};

#endif //_CCONFIGURATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
