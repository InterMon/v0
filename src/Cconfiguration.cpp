/* $Id$
 * $Version: 7.3.0$
 * $Revision: 8$
 */
/**
 * Project InterMon v0.7.3
 */

#include "Cconfiguration.h"

const std::string devNull = "/dev/null";
const char chost[] = "host";
const char cip[] = "ip";

Cconfiguration::Cconfiguration(const std::string & s)
: cfgxml(s.c_str()) { }

Cconfiguration::~Cconfiguration() { }

int Cconfiguration::parse() {
    if (_config.size() > 0) {
        std::cerr << "Configuration: "
                  << this->name
                  << " already defined"
                  << std::endl;
        return 1;
    }
#if defined(DEBUG) && defined(PRINTM)
    printd("Prepare Cconfiguration") << std::endl;
#endif
    if(!cfgxml.LoadFile()) {
        std::cout << "file "
                  << cfgxml.Value()
                  << " have any errors"
                  << std::endl;
        return 2;
    }
    TiXmlElement *xml1 = 0;
    xml1 = cfgxml.FirstChildElement();
    TiXmlElement *xml2 = 0;
    xml2 = xml1->FirstChildElement(chost);
    while(nullptr != xml2) {
        const char * name = xml2->Attribute("name");
        if (nullptr != name) {
            _config.push_back(chost);
            _config.push_back(name);
            const char * ip = xml2->Attribute(cip);
            if (nullptr != ip) {
                _config.push_back(cip);
                _config.push_back(ip);
                std::cout << "Added host: " << name
                          << " ip: " << ip
                          << std::endl;
            } else {
                std::cout << "Added host: " << name
                          << " UNKNOW ip!!!" << std::endl;
            }
        }
        _config.push_back("");
        xml2 = xml2->NextSiblingElement(chost);
    }
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
