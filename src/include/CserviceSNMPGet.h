/* $Id$
 * $Version: 0.7$
 * $Revision: 6$
 */
/**
 * Project InterMon v0.7
 */


#ifndef _CSERVICESNMPGET_H
#define _CSERVICESNMPGET_H

#include "InterMon.h"
#include "Cservice.h"


class CserviceSNMPGet: public Cservice {
public: 
    /* */
    CserviceSNMPGet();
    /* */
    ~CserviceSNMPGet();
    /* */
    void checkCommand();
    /* */
    void notifyCommand();
protected: 
    std::string community;
};

#endif //_CSERVICESNMPGET_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
