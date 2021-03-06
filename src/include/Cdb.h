/* $Id$
 * $Version: 0.8$
 * $Revision: 27$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _CDB_H
#define _CDB_H

#include <string>
#include <stdexcept>
#include "Cbasic.h"
#include "sqlite_modern_cpp.h"

class Cdb: public Cbasic {
private:
    sqlite::database _db = {":memory:"};
public: 
    /* */
    Cdb();
    /* */
    void backup(const std::string & name = "sqlite3.db")
        throw(std::runtime_error);
    /* */
    void addHost(const std::string & name);
    /* */
    int getHostStatus(const std::string & name);
    /* */
    void setHostStatus(const std::string & name, int status);

    /* */
    ~Cdb();
};

extern Cdb mdb;

#endif //_CDB_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
