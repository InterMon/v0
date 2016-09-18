/* $Id$
 * $Version: 0.7.2$
 * $Revision: 7$
 */
/**
 * Project InterMon v0.7.2
 */

#ifndef _CCONFIGURATION_H
#define _CCONFIGURATION_H

#include "InterMon.h"
#include "Cname.h"
#include "tinyxml.h"
#include <fstream>      // std::ifstream

extern const std::string devNull;

class Cconfiguration: public Cname {
public:
    Cconfiguration(const std::string & s = devNull);
    explicit Cconfiguration(const char ** c) {
        char ** p = const_cast<char **>(c);
        for (; *p != nullptr; ++p) {
            _config.push_back(*p);
        }
    }
    ~Cconfiguration();
    int parse();
    const std::vector<std::string> & config() {
        return _config;
    }
private:
    TiXmlDocument cfgxml;
    std::vector<std::string> _config;
};

#endif //_CCONFIGURATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
