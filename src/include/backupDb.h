/* $Id$
 * $Version: 0.8$
 * $Revision: 12$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _BACKUPDB_H
#define _BACKUPDB_H

#include "sqlite_modern_cpp.h"

namespace sqlite {
    class database;
    extern int
    backupDb(database * db, const char *zFilename, void(*xProgress)(int, int));
}

#endif //_BACKUPDB_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
