/* $Id$
 * $Version: 0.7.1$
 * $Revision: 8$
 */
/**
 * Project InterMon v0.7.1
 */

#define _MODERN_SQLITE_BOOST_OPTIONAL_SUPPORT
#include "Cdb.h"

using namespace sqlite;
using namespace std;

Cdb::Cdb() {
    db << "CREATE TABLE hosts"
          " ( id    INTEGER PRIMARY KEY NOT NULL"
          " , name  TEXT UNIQUE NOT NULL "
          " , state INTEGER state );";
}

Cdb::~Cdb() { /* empty */ }

void Cdb::addHost(const std::string & name) {
    try {
        db << "INSERT INTO hosts (name) VALUES (?)"
           << name;
    }
    catch (sqlite_exception& e) {
        cerr << e.what() << endl;
    }
}

int Cdb::getHostStatus(const std::string & name) {
    int result = 0;
    db << "SELECT state FROM hosts WHERE name = ?"
       << name >> result;
    return result;
}

void Cdb::setHostStatus(const std::string & name, int status) {
    db << "UPDATE hosts SET state = ? WHERE name = ?"
       << status << name;
}

Cdb mdb;

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
