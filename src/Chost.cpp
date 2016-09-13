/* $Id$
 * $Version: 0.7$
 */
/**
 * Project InterMon v0.7
 */


#include "Chost.h"

Chost::Chost() { /* empty */ }

Chost::~Chost() { /* empty */ }

void Chost::checkCommand() {
#if defined(DEBUG) && defined(PRINTM)
    printd("check host: ", hostName) << std::endl;
#endif
    // TODO
    std::cerr << "ping host: " << hostName << std::endl;
}

void Chost::checkServices() {
    // TODO
}

void Chost::notifyCommand() {
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
