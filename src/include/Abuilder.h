/* $Id$
 * $Version: 0.8$
 * $Revision: 10$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef ABUILDER_H
#define ABUILDER_H

#include "Chost.h"
#include "tinyxml.h"
#include <string>

/**
  * class Abuilder
  * title Abstract builder
  * goals Implement Design Patterns: Bulder
  */

class Abuilder {
public:
    /**
     * Empty default Constructor
     */
    Abuilder() = default;

    /**
     * @param  xml
     */
    Abuilder(TiXmlElement * xml) { /* Empty */ }

    /**
     * @return Aservice *
     */
    virtual Aservice * buildPart(TiXmlElement *) = 0;

    /**
     * @return Chost *
     */
    virtual Chost * getResult() = 0;

    /**
     * Empty Destructor
     */
    virtual ~Abuilder() { /* Empty */ }
};

#endif // ABUILDER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
