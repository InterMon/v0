/* $Id$
 * $Version: 0.8$
 * $Revision: 12$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef CBUILDER_H
#define CBUILDER_H

#include "Abuilder.h"
#include "Aservice.h"
#include "tinyxml.h"
#include <string>
#include <stdexcept>

/**
  * class: Cbuilder
  * title: Сoncrete builder
  * goals: Implement Design Patterns: Bulder
  *
  * Concrete class implementing the Abuilder interface.
  * Instance of Concrete class is built using data from xml.
  * Then create a Chost class having Array(std::vector) of service instances.
  * Method getResult produce desired product of instance Chost.
  * Method buildPart prepare specific service for desired host.
  */

class Cbuilder : public Abuilder {
private:
    TiXmlElement * _xml;
public:
    /**
     * No default Constructor
     */
    Cbuilder() = delete;

    /**
     * Constructor
     * @param xml - Pointer to XML Element
     */
    Cbuilder(TiXmlElement * xml)
    : _xml(xml) { /* Empty*/ }

    // Copy Constructor no copy!
    Cbuilder(const Cbuilder & other)
    : _xml(nullptr) { /* Empty */ }

    Cbuilder & operator=(const Cbuilder & other) {
        _xml = nullptr;
        return *this;
    }

    /**
     * @return Aservice *
     */
    Aservice * buildPart(TiXmlElement * xmle) throw(std::bad_alloc);

    /**
     * @return Chost *
     */
    Chost * getResult() throw(std::bad_alloc);

    /**
     * Empty Destructor
     */
    virtual ~Cbuilder() { /* Empty */ }
};

#endif // CBUILDER_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
