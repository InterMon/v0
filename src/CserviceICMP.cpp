/* $Id$
 * $Version: 0.8$
 * $Revision: 19$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "InterMon.h"
#include "CserviceICMP.h"

Aservice *
CctreatorServiceICMP::factoryMethod()
throw(std::bad_alloc)
{
  if (nullptr == _xml) return nullptr;
  const char * name = _xml->Attribute(cAttrName.c_str());
  if (cAttrNameValue != name) return nullptr;
  const char * type = _xml->Attribute(cAttrType.c_str());
  // TODO convert "type" to an int and this value will be use as parameter for:
  return new CserviceICMP(name);
}

Acommand *
CserviceICMP::getCheckCommand()
throw(std::bad_alloc)
{
    return new Ccommand<CserviceICMP>(this, &CserviceICMP::checkCommand);
}

CserviceICMP::CserviceICMP(std::string description)
: Aservice(description), _icmpType(8)
{
    // TODO
}

CserviceICMP::CserviceICMP(const CserviceICMP & other)
{
    // TODO
}

CserviceICMP &
CserviceICMP::operator=(const CserviceICMP & )
{
    return *this;
}

CserviceICMP::~CserviceICMP()
{
    // TODO
}

void
CserviceICMP::checkCommand()
{
#if defined(DEBUG) && defined(PRINTM)
    printd("service icmp check: ", _icmpType) << std::endl;
#endif
}

void
CserviceICMP::notifyCommand()
{
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
