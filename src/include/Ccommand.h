/* $Id$
 * $Version: 0.8$
 * $Revision: 10$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef CCOMMAND_H
#define CCOMMAND_H

#include "Acommand.h"
#include <string>

/**
  * class Ccommand
  * title Сoncrete command
  * goals Implement Design Patterns: Command
  * Concrete class implementing the Acommand interface.
  *
  * Create a class that encapsulates an object and a member function
  * a pointer to a member function (the attribute's name is "Action")
  * Receiver:- Knows how to perform the command "Action".
  *
  */

template <class Receiver>
class Ccommand : public Acommand {
public:
    typedef void (Receiver::* Action)();
    // Constructor
    Ccommand(Receiver * r, Action a)
    : _state(0), _action(a), _receiver(r)
    { /* Empty */ }

    void execute() {
        (_receiver->*_action)();
    }

    // Private attribute accessor methods
    /**
     * Set the value of state
     * @param new_var the new value of state
     */
    void setState(int new_var) {
        _state = new_var;
    }

    /**
     * Get the value of state
     * @return the value of state
     */
    int getState() {
      return _state;
    }

    Aservice * getReceiver() const {
        return _receiver;
    }

    /**
     * Empty Destructor
     */
    virtual ~Ccommand() { /* Empty */ }
private:
    // Private attributes
    int        _state;
    Action     _action;
    Receiver * _receiver;
};

#endif // CCOMMAND_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
