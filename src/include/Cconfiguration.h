/* $Id$
 * $Version: 0.8$
 * $Revision: 21$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CCONFIGURATION_H
#define _CCONFIGURATION_H

#include <string>
#include "tinyxml.h"
#include "Chost.h"
#include "Sname.h"
#include "Acommand.h"
#include "strs.h"

/**
  * class Cconfiguration
  * title Сoncrete configuration
  * goals 
  * Configuration input and build routines.
  *
  * Method parse read all configuration data.
  * Method read in all host configuration data from xmlhost.
  * Method read in all host configuration data from xmlhost.
  */

class Cconfiguration: public Sname {
private:
    TiXmlDocument _cfgxml;
public:
    Cconfiguration(const std::string & s = devNull)
    : _cfgxml(s.c_str()) { /* Empty */ }

    int parse(std::vector<Chost*> & hosts);

    /**
     * Empty Destructor
     */
    ~Cconfiguration() { /* Empty */ }
private:
    void parseHost(std::vector<Chost*> & hosts, TiXmlElement * xmlhost);
    Acommand * parseGetCommand(Aservice * service, TiXmlElement * xmlservice);
};

#endif //_CCONFIGURATION_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
