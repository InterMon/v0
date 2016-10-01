/* $Id$
 * $Version: 7.3.0$
 * $Revision: 4$
 */
/**
 * Project InterMon v0.7.3
 */

#pragma once
#ifndef ACREATOR_H
#define ACREATOR_H

#include "tinyxml.h"
#include "Aservice.h"
#include <string>

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

  // Destructor
  virtual ~Acreator() { /* Empty */ }

  /**
   * @return pointer to Aservice 
   */
  virtual Aservice * factoryMethod() = 0;
};

#endif // ACREATOR_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
