/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 21$
=======
 * $Revision: 20$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

#define _MODERN_SQLITE_BOOST_OPTIONAL_SUPPORT

#include <iostream>
#include "Cdb.h"
#include "backupDb.h"

using namespace sqlite;
using namespace std;

Cdb::Cdb()
{
    _db << "CREATE TABLE hosts"
           " ( id    INTEGER PRIMARY KEY NOT NULL"
           " , name  TEXT UNIQUE NOT NULL "
           " , state INTEGER state );";
}

Cdb::~Cdb()
{
    sqlite::backupDb(&this->_db, "sqlite3.db", NULL);
}

void
Cdb::backup(const std::string & name) throw(std::runtime_error)
{
#if defined(DEBUG) && defined(PRINTM)
    cerr << "running..." << endl;
#endif
    int rc = 0;
    if (0 == (rc = sqlite::backupDb(&this->_db, name.c_str(), NULL))) {
#if defined(DEBUG) && defined(PRINTM)
        printd("Ok! rc: ", rc) << endl;
#endif
    } else {
#if defined(DEBUG) && defined(PRINTM)
        printd("Error in backup rc: ", rc) << endl;
#endif
        throw std::runtime_error("Error in backup");
    }
}

void
Cdb::addHost(const std::string & name)
try {
    _db << "INSERT INTO hosts (name) VALUES (?)"
        << name;
}
catch (sqlite_exception& e) {
    cerr << e.what() << endl;
}

int
Cdb::getHostStatus(const std::string & name)
{
    int result = 0;
    _db << "SELECT state FROM hosts WHERE name = ?"
        << name >> result;
    return result;
}

void
Cdb::setHostStatus(const std::string & name, int status)
try {
    _db << "UPDATE hosts SET state = ? WHERE name = ?"
        << status << name;
}
catch (sqlite_exception& e) {
    cerr << e.what() << endl;
}

Cdb mdb;

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
