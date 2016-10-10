/* $Id$
 * $Version: 0.8$
 * $Revision: 23$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "Cdb.h"
#include "Chost.h"

using namespace std;

typedef vector<Acommand*>::iterator cIter;

Chost::~Chost()
{
    CservicesIterator services = getServicesIterator();
    while (services.hasNext()) {
        delete services.next();
    }
    for (cIter iCmd = _commands.begin(); iCmd != _commands.end(); ++iCmd) {
        Acommand * ptrCommand = *iCmd;
        delete ptrCommand;
    }
}

void
Chost::checkCommand()
{
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

void
Chost::checkServices()
{
    CservicesIterator services = getServicesIterator();
    while (services.hasNext()) {
        services.next()->checkCommand();
    }
}

void
Chost::notifyCommand()
{
    // TODO
}

void
Chost::addService(Aservice * service)
{
    if (nullptr == service) return;
#if defined(DEBUG) && defined(PRINTM)
    printd("add service!") << endl;
#endif
    _services.push_back(service);
}

void
Chost::AddCommand(Acommand * command)
{
    if (nullptr == command) return;
#if defined(DEBUG) && defined(PRINTM)
    printd("add service!") << endl;
#endif
    _commands.push_back(command);
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
