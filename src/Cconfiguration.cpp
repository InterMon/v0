/* $Id$
 * $Version: 0.6$
 */
/**
 * Project InterMon v0.6
 */


#include "Cconfiguration.h"

const std::string devNull = "/dev/null";

Cconfiguration::Cconfiguration(std::string s = devNull) {
  if (s != devNull) {
#if defined(DEBUG) && defined(PRINTM)
    printd("Prepare Cconfiguration") << std::endl;
#endif
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
    /* parsing ... */
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
