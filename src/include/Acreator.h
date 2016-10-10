/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 11$
=======
 * $Revision: 10$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef ACREATOR_H
#define ACREATOR_H

#include <string>
#include "tinyxml.h"
#include "Aservice.h"

/**
  * class Acreator
  */

class Acreator {
public:
    // Constructors
    Acreator() = default;

    /**
     * @param xml - Pointer to XML Element
     */
    Acreator(TiXmlElement * xml) { /* Empty */ }

    /**
     * @return pointer to Aservice
     */
    virtual Aservice * factoryMethod() = 0;

    /**
     * Empty Destructor
     */
    virtual ~Acreator() { /* Empty */ }
};

#endif // ACREATOR_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
