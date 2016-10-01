/* $Id$
 * $Version: 7.3.0$
 * $Revision: 3$
 */
/**
 * Project InterMon v0.7.3
 */

#pragma once
#ifndef CCTREATORSERVICEICMP_H
#define CCTREATORSERVICEICMP_H

#include "Acreator.h"
#include "CserviceICMP.h"
#include "tinyxml.h"
#include <string>

/**
  * class CctreatorServiceICMP
  */

class CctreatorServiceICMP : public Acreator {
public:
    /**
     * Constructor
     * @param xml - Pointer to XML Element
     */
    CctreatorServiceICMP(TiXmlElement * xml)
    : _xml(xml) { /* Empty */ }

    // Destructor
    virtual ~CctreatorServiceICMP() { /* Empty */ }

    /**
     * @return pointer to CserviceICMP
     *  method return null pointer if some error!
     */
    Aservice * factoryMethod();

private:
    TiXmlElement * _xml;
};

#endif // CCTREATORSERVICEICMP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
