/* $Id$
 * $Version: 0.7.1$
 * $Revision: 7$
 */
/**
 * Project InterMon v0.7.1
 */

#include "Chost.h"

using namespace std;

Chost::Chost() { /* empty */ }

Chost::~Chost() { /* empty */ }

void Chost::checkCommand() {
#if defined(DEBUG) && defined(PRINTM)
    printd("check host: ", hostName) << endl;
#endif
    // TODO
    cerr << "ping host: " << hostName << " this: " << this << endl;
    mdb.setHostStatus(hostName, 0);
}

void Chost::checkServices() {
    // TODO
}

void Chost::notifyCommand() {
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
