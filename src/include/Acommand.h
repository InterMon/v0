/* $Id$
 * $Version: 7.3.1$
 * $Revision: 1$
 */
/**
 * Project InterMon $Version: 0.7.3
 */

#pragma once
#ifndef ACOMMAND_H
#define ACOMMAND_H

#include <string>
#include <vector>

/**
  * class Acommand
  */

class Acommand {
public:
  /// Empty Destructor
  virtual ~Acommand() { /* Empty */ }

  virtual void execute() = 0;
};

#endif // ACOMMAND_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */