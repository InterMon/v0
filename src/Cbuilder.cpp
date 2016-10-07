/* $Id$
 * $Version: 0.8$
 * $Revision: 5$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "CserviceICMP.h"
#include "CserviceSNMPGet.h"
#include "Cbuilder.h"
#include "strs.h"

Aservice *
Cbuilder::buildPart(TiXmlElement * xmle)
throw(std::bad_alloc)
{
    if (nullptr == xmle) return nullptr;
    const char * name = xmle->Attribute(cAttrName.c_str());
    Aservice *service = nullptr;
    CctreatorServiceICMP creator(xmle);
    if (nullptr != (service = creator.factoryMethod()))
        return service;
    return nullptr;
}

Chost *
Cbuilder::getResult()
throw(std::bad_alloc)
{
    if (nullptr == _xml) return nullptr;
    const char * name = _xml->Attribute(cAttrName.c_str());
    if (nullptr == name) return nullptr;
#if defined(DEBUG) && defined(PRINTM)
    printd("hostname: ", name) << std::endl;
#endif
    return new Chost(name);
}

void test() {
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
