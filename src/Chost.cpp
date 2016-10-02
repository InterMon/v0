/* $Id$
 * $Version: 7.4.0$
 * $Revision: 18$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#include "Chost.h"

using namespace std;

typedef vector<Aservice*>::iterator sIter;

Chost::~Chost() {
    for (sIter i = _services.begin(); i != _services.end(); ++i) {
        delete *i;
    }
}

void Chost::checkCommand() {
#if defined(DEBUG) && defined(PRINTM)
    printd("check host: ", _hostName) << endl;
#endif
    // TODO
    mdb.setHostStatus(_hostName, 0);
#if defined(DEBUG) && defined(PRINTM)
    printd(" ping host: ", _hostName, " this: ", this) << endl;
#endif
    checkServices();
}

void Chost::checkServices() {
    for (sIter i = _services.begin(); i != _services.end(); ++i) {
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
    _services.push_back(service);
}
/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
