/* $Id$
 * $Version: 0.8$
 * $Revision: 19$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CSERVICEICMP_H
#define _CSERVICEICMP_H

#include <stdexcept>
#include "tinyxml.h"
#include "Acreator.h"
#include "Aservice.h"
#include "Ccommand.h"
#include "strs.h"

/**
  * class CserviceICMP
  */
class CserviceICMP: public Aservice {
public:
    /* */
    CserviceICMP() = delete;
    CserviceICMP(std::string description);
    // Copy Constructor
    CserviceICMP(const CserviceICMP & );
    /* */
    CserviceICMP & operator=(const CserviceICMP & );
    /* */
    void checkCommand();
    /* */
    void notifyCommand();
    /* */
    Acommand * getCheckCommand() throw(std::bad_alloc);

    /**
     * Destructor
     */
    ~CserviceICMP();
private:
    int _icmpType;
};

class CctreatorServiceICMP : public Acreator {
public:
    // Remove Empty Constructor
    CctreatorServiceICMP() = delete;

    /**
     * Constructor
     * @param xml - Pointer to XML Element
     */
    CctreatorServiceICMP(TiXmlElement * xml)
    : _xml(xml) { /* Empty */ }

    // Copy Constructor no copy!
    CctreatorServiceICMP(const CctreatorServiceICMP & )
    : _xml(nullptr) { /* Empty */ }

    CctreatorServiceICMP & operator=(const CctreatorServiceICMP & ) {
        _xml = nullptr;
        return *this;
    }

    /**
     * @return pointer to CserviceICMP
     *  method return null pointer if some error!
     */
    Aservice * factoryMethod() throw(std::bad_alloc);

    /**
     * Empty Destructor
     */
    virtual ~CctreatorServiceICMP() { /* Empty */ }
private:
    TiXmlElement * _xml;
};

#endif //_CSERVICEICMP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
