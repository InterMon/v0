/* $Id$
 * $Version: 0.8$
 * $Revision: 8$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef ACOMMAND_H
#define ACOMMAND_H

#include <string>
#include <vector>

class Aservice;

/**
  * class Acommand
  * title Abstract command
  * goals Implement Design Patterns: Command
  */

class Acommand {
public:
    virtual void execute() = 0;
    virtual Aservice * getReceiver() const = 0;

    /**
     * Empty Destructor
     */
    virtual ~Acommand() { /* Empty */ }
};

#endif // ACOMMAND_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
