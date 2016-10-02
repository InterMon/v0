/* $Id$
 * $Version: 7.4.0$
 * $Revision: 4$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#include "CctreatorServiceICMP.h"

const std::string cAttrName = "name";
const std::string cAttrNameValue = "icmp";
const std::string cAttrType = "type";

Aservice * CctreatorServiceICMP::factoryMethod() {
  if (nullptr == _xml) return nullptr;
  const char * name = _xml->Attribute(cAttrName.c_str());
  if (cAttrNameValue != name) return nullptr;
  const char * type = _xml->Attribute(cAttrType.c_str());
  // TODO convert "type" to an int and this value will be use as parameter for:
  return new CserviceICMP();
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
