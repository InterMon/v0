/* $Id$
 * $Version: 0.5$
 */
/**
 * Project InterMon v0.5
 */


#include "Cconfiguration.h"

const std::string devNull = "/dev/null";

Cconfiguration::Cconfiguration(std::string s = "/dev/null") {
  if (s != devNull) {
    std::cerr << "Prepare Cconfiguration" << std::endl;
  }
}

Cconfiguration::~Cconfiguration() { }

int Cconfiguration::parse() { return 0; }

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
