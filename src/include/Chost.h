/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 22$
=======
 * $Revision: 21$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CHOST_H
#define _CHOST_H

#include <queue>
#include <string>
#include "Acheck.h"
#include "Aiterator.h"
#include "CipAddress.h"
#include "Cnotification.h"
#include "Aservice.h"
#include "Acommand.h"
#include "Ccommand.h"

class Chost: public Acheck, public Cnotification {
private:
    typedef std::vector<Aservice*> SetOfServices;
    typedef std::vector<Acommand*> SetOfCommands;
    std::string    _hostName;
    CipAddress     _ipAddress;
    SetOfServices  _services;
    SetOfCommands  _commands;
public:
    Chost() = default;
    Chost(const std::string & name)
    : _hostName(name) { /* empty */ }

    /* */
    void checkCommand();

    /* */
    void checkServices();

    /* */
    void notifyCommand();

    /* */
    const std::string & getHostname() const { return _hostName; };

    /* */
    void addService(Aservice * service);

    /* */
    void AddCommand(Acommand * command);

    /* */
    friend class CservicesIterator;

    class CservicesIterator: public Aiterator<SetOfServices::value_type> {
        friend class Chost;
    private:
        Chost::SetOfServices &         _services;
        Chost::SetOfServices::iterator _itr;
        CservicesIterator(Chost::SetOfServices & services)
        : _services(services), _itr(_services.begin()) {}
    public:
        virtual bool hasNext() {
            return _itr != _services.end();
        }
        virtual CservicesIterator::value_type next(void) {
            CservicesIterator::value_type value = (*_itr);
            ++_itr;
            return value;
        }
     };

    /* */
    CservicesIterator getServicesIterator() {
        return CservicesIterator(_services);
    }

    /* */
    friend class CcommandsIterator;

    class CcommandsIterator: public Aiterator<SetOfCommands::value_type> {
        friend class Chost;
    private:
        Chost::SetOfCommands &         _commands;
        Chost::SetOfCommands::iterator _itr;
        CcommandsIterator(Chost::SetOfCommands & commands)
        : _commands(commands), _itr(_commands.begin()) {}
    public:
        virtual bool hasNext() {
            return _itr != _commands.end();
        }
        virtual CcommandsIterator::value_type next(void) {
            CcommandsIterator::value_type value = (*_itr);
            ++_itr;
            return value;
        }
     };

    /* */
    CcommandsIterator getCommandsIterator() {
        return CcommandsIterator(_commands);
    }

    /**
     * Destructor
     */
    ~Chost();
};

#endif //_CHOST_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
