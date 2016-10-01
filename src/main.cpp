/* $Id$
 * $Version: 7.3.0$
 * $Revision: 12$
 */
/**
 * Project InterMon v0.7.3
 */

#include "CmainServer.h"
#include "Cname.h"
#include "Cconfiguration.h"
#include "CserviceICMP.h"

const char __version__[] = "Project InterMon $Version: 0.7.3";

using namespace sqlite;
using namespace std;

#define MAXLINE 255
#define __TEST_DEVELOPING__ true

int main(int argc, char *argv[]) {
#if defined(DEBUG) && defined(PRINTM)
    printd("argc: ", argc, "; argv: ", argv) << endl;
#endif
#if defined(__TEST_DEVELOPING__)
    CmainServer mainServer("test.xml"); 
    mainServer.init();
    mainServer.run();
#else
    CmainServer mainServer(charsTestConf);
    mainServer.init();
    mainServer.run();
#endif
    char * _version_ = const_cast<char *>(__version__);
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
