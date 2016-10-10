/* $Id$
 * $Version: 0.8$
 * $Revision: 22$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CSERVICE_H
#define _CSERVICE_H

#include "Acheck.h"
#include "Acommand.h"
#include "Cnotification.h"

class Aservice: public Acheck, public Cnotification {
protected:
    std::string _description;
public:
    /* */
    Aservice() { /* empty */ };
    /* */
    Aservice(std::string desc)
    : _description(desc) { /* empty */ };
    /* */
    virtual const std::string & getDescription() const {
        return _description;
    }
    /* */
    virtual void checkCommand() = 0;
    /* */
    virtual void notifyCommand() = 0;
    /* */
    virtual Acommand * getCheckCommand() = 0;

    /**
     * Empty Destructor
     */
    virtual ~Aservice() { /* empty */ };
};

#endif //_CSERVICE_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
