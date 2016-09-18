/* $Id$
 * $Version: 0.7.2$
 * $Revision: 5$
 */
/**
 * Project InterMon v0.7.2
 */

#include "Cconfiguration.h"
#include "tinyxml.h"

const std::string devNull = "/dev/null";

Cconfiguration::Cconfiguration(const std::string & s) {
  if (s != devNull) {
#if defined(DEBUG) && defined(PRINTM)
    printd("Prepare Cconfiguration") << std::endl;
#endif
    TiXmlDocument cfg(s.c_str());
    
    if(!cfg.LoadFile()) {
        std::cout << "file " << cfg.Value() << " have any errors" << std::endl;
        return;
    }
    TiXmlElement *xml1 = 0;
    xml1 = cfg.FirstChildElement();
    TiXmlElement *xml2 = 0;
    xml2 = xml1->FirstChildElement("host");
    while(xml2 != nullptr) {
        const char * name = xml2->Attribute("name");
        std::cout << name << std::endl;
        _config.push_back("host");
        _config.push_back(name);
        xml2 = xml2->NextSiblingElement("host");
    }
  }
}

Cconfiguration::~Cconfiguration() { }

int Cconfiguration::parse() {
    if (_config.size() > 0) {
        std::cerr << "Configuration: "
                  << this->name
                  << " already defined"
                  << std::endl;
        return 1;
    }
    // TODO
    /* parsing ... */
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
