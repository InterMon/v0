/* $Id$
 * $Version: 7.3.1$
 * $Revision: 1$
 */
/**
 * Project InterMon $Version: 0.7.3
 */

#pragma once
#ifndef CCOMMAND_H
#define CCOMMAND_H

#include "Acheck.h"
#include "Acommand.h"
#include "Chost.h"
#include <string>

/**
  * class Ccommand
  */

template <class Receiver>
class Ccommand : public Acommand {
public:
    typedef void (Receiver::* Action)();
    // Constructor
    Ccommand(Receiver * r, Action a)
    : _state(0), _action(a), _receiver(r)
    { /* Empty */ }

    /**
     * Destructor
     */
    virtual ~Ccommand() { /* Empty */ }

    void execute() {
        (_receiver->*_action)();
    }

    // Private attribute accessor methods
    /**
     * Set the value of state
     * @param new_var the new value of state
     */
    void setState(int new_var)   {
        _state = new_var;
    }

    /**
     * Get the value of state
     * @return the value of state
     */
    int getState()   {
      return _state;
    }
private:
    // Private attributes
    int        _state;
    Action     _action;
    Receiver * _receiver;
};

#endif // CCOMMAND_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */

