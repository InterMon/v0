/* $Id$
 * $Version: 7.4.0$
 * $Revision: 22$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#pragma once
#ifndef _CDB_H
#define _CDB_H

#include "InterMon.h"
#include "Cname.h"
#include "Acheck.h"
#include "CipAddress.h"
#include "Cipv4Address.h"
#include "Cnotification.h"
#include "Aservice.h"
#include "sqlite_modern_cpp.h"

class Cdb: public Cbasic {
public: 
    /* */
    Cdb();
    /* */
    ~Cdb();
    /* */
    void backup(const std::string & name = "sqlite3.db")
        throw(std::runtime_error);
    /* */
    void addHost(const std::string & name);
    /* */
    int getHostStatus(const std::string & name);
    /* */
    void setHostStatus(const std::string & name, int status);
private: 
    sqlite::database _db = {":memory:"};
};

extern Cdb mdb;

#endif //_CDB_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
