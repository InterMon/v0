/* $Id$
 * $Version: 7.3.0$
 * $Revision: 15$
 */
/**
 * Project InterMon v0.7.3
 */

#include "Chost.h"

using namespace std;

typedef vector<Aservice*>::iterator sIter;

Chost::Chost() { /* empty */ }

Chost::~Chost() {
    for (sIter i = services.begin(); i != services.end(); ++i) {
        delete *i;
    }
}

void Chost::checkCommand() {
#if defined(DEBUG) && defined(PRINTM)
    printd("check host: ", hostName) << endl;
#endif
    // TODO
    mdb.setHostStatus(hostName, 0);
#if defined(DEBUG) && defined(PRINTM)
    printd(" ping host: ", hostName, " this: ", this) << endl;
#endif
    checkServices();
}

void Chost::checkServices() {
    for (sIter i = services.begin(); i != services.end(); ++i) {
        (*i)->checkCommand();
    }
}

void Chost::notifyCommand() {
    // TODO
}

void Chost::addService(Aservice * service) {
#if defined(DEBUG) && defined(PRINTM)
    printd("add service!") << endl;
#endif
    if (nullptr == service) return;
    services.push_back(service);
}
/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
