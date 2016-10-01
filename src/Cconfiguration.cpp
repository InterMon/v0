/* $Id$
 * $Version: 7.3.0$
 * $Revision: 11$
 */
/**
 * Project InterMon v0.7.3
 */

#include "Cconfiguration.h"

const std::string devNull = "/dev/null";
const char chost[] = "host";
const char cservice[] = "service";
const char cip[] = "ip";

Cconfiguration::Cconfiguration(const std::string & s)
: cfgxml(s.c_str()) { }

Cconfiguration::~Cconfiguration() { }

int Cconfiguration::parse(std::vector<Chost*> & hosts) {
    if(!cfgxml.LoadFile()) {
        std::cout << "file "
                  << cfgxml.Value()
                  << " have any errors" << std::endl;
        return 2;
    }
    TiXmlElement * xmlconfig = cfgxml.FirstChildElement();
    if (nullptr == xmlconfig) return 3;
    TiXmlElement * xmlhost = xmlconfig->FirstChildElement(chost);
    while(nullptr != xmlhost) {
        Cbuilder builder(xmlhost);
        Chost * host = nullptr;
        if (nullptr != (host = builder.getResult())) {
            hosts.push_back(host);
            mdb.addHost(host->getHostname());
            TiXmlElement * xmlservice = xmlhost->FirstChildElement(cservice);
            while(nullptr != xmlservice) {
                Aservice * service = builder.buildPart(xmlservice);
                xmlservice = xmlservice->NextSiblingElement(chost);
                host->addService(service);
            }
        }
        xmlhost = xmlhost->NextSiblingElement(chost);
    }
    return 0;
}
/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
