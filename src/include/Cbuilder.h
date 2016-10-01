/* $Id$
 * $Version: 7.3.0$
 * $Revision: 3$
 */
/**
 * Project InterMon v0.7.3
 */

#pragma once
#ifndef CBUILDER_H
#define CBUILDER_H
#include "Abuilder.h"
#include "Aservice.h"
#include "CctreatorServiceICMP.h"
#include "tinyxml.h"
#include <string>

/**
  * class Cbuilder
  * 
  */

const std::string cAttrName = "name";

class Cbuilder : public Abuilder {
public:
    // Remove Empty Constructor
    Cbuilder() = delete;

    /**
     * Constructor
     * @param xml - Pointer to XML Element
     */
    Cbuilder(TiXmlElement * xml)
    : _xml(xml) { }

    // Destructor
    virtual ~Cbuilder() { /* Empty */ }

    /**
     * @return Aservice *
     */
    Aservice * buildPart(TiXmlElement * xmle);

    /**
     * @return Chost *
     */
    Chost * getResult();

    // Private attribute accessor methods
private:
    TiXmlElement * _xml;
};

#endif // CBUILDER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
