/* $Id$
 * $Version: 7.3.0$
 * $Revision: 1$
 */
/**
 * Project InterMon v0.7.3
 */

#include "Cbuilder.h"

Aservice * Cbuilder::buildPart(TiXmlElement * xmle) {
    if (nullptr == xmle) return nullptr;
    const char * name = xmle->Attribute(cAttrName.c_str());
#if defined(DEBUG) && defined(PRINTM)
    printd("servicename: ", name) << std::endl;
#endif
    Aservice *service = nullptr;
    CctreatorServiceICMP creator(xmle);
    if (nullptr != (service = creator.factoryMethod()))
        return service;
    return nullptr;
}

Chost * Cbuilder::getResult() {
    if (nullptr == _xml) return nullptr;
    const char * name = _xml->Attribute(cAttrName.c_str());
    if (nullptr == name) return nullptr;
#if defined(DEBUG) && defined(PRINTM)
    printd("hostname: ", name) << std::endl;
#endif
    return new Chost(name);
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
