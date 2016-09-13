/* $Id$
 * $Version: 0.7$
 * $Revision: 6$
 */
/**
 * Project InterMon v0.7
 */


#ifndef _CSERVICEICMP_H
#define _CSERVICEICMP_H

#include "InterMon.h"
#include "Cservice.h"


class CserviceICMP: public Cservice {
public: 
    /* */
    CserviceICMP();
    /* */
    ~CserviceICMP();
    /* */
    void checkCommand();
    /* */
    void notifyCommand();
private: 
    int icmpType;
};

#endif //_CSERVICEICMP_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
