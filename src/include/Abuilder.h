/* $Id$
 * $Version: 7.4.0$
 * $Revision: 7$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef ABUILDER_H
#define ABUILDER_H

#include "Chost.h"
#include "tinyxml.h"
#include <string>

/**
  * class Abuilder
  */

class Abuilder {
public:
    /// Constructors
    Abuilder() = default;
    /**
     * @param  xml
     */
    Abuilder(TiXmlElement * xml) { /* Empty */ }


    /**
     * Empty Destructor
     */
    virtual ~Abuilder() { /* Empty */ }

    /**
     * @return Aservice *
     */
    virtual Aservice * buildPart(TiXmlElement *) = 0;

    /**
     * @return Chost *
     */
    virtual Chost * getResult() = 0;
};

#endif // ABUILDER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
