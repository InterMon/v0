/* $Id$
 * $Version: 0.8$
 * $Revision: 20$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include <queue>
#include <iostream>
#include "Cbuilder.h"
#include "Cdb.h"
#include "Cconfiguration.h"
#include "strs.h"

Acommand *
Cconfiguration::parseGetCommand(Aservice * service, TiXmlElement * xmlservice)
{
    return service->getCheckCommand();
}

void
Cconfiguration::parseHost(std::vector<Chost*> & hosts, TiXmlElement * xmlhost)
try {
    Cbuilder builder(xmlhost);
    Chost * host = nullptr;
    if (nullptr == (host = builder.getResult()))
        return;
    hosts.push_back(host);
    mdb.addHost(host->getHostname());
    TiXmlElement * xmlservice = xmlhost->FirstChildElement(cservice);
    while (nullptr != xmlservice) {
        Aservice * service = builder.buildPart(xmlservice);
        if (nullptr != service) {
            host->addService(service);
            Acommand * cmd = parseGetCommand(service, xmlservice);
            if (nullptr != cmd) {
                host->AddCommand(cmd);
            }
            xmlservice = xmlservice->NextSiblingElement(chost);
        }
    }
}
catch (std::bad_alloc & e) {
    std::cerr << e.what() << std::endl;
}

int
Cconfiguration::parse(std::vector<Chost*> & hosts)
{
    if (!_cfgxml.LoadFile()) {
        std::cout << "file "
                  << _cfgxml.Value()
                  << " have any errors" << std::endl;
        return 2;
    }
    TiXmlElement * xmlconfig = _cfgxml.FirstChildElement();
    if (nullptr == xmlconfig) return 3;
    TiXmlElement * xmlhost = xmlconfig->FirstChildElement(chost);
    while (nullptr != xmlhost) {
        parseHost(hosts, xmlhost);
        xmlhost = xmlhost->NextSiblingElement(chost);
    }
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
