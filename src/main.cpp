/* $Id$
 * $Version: 7.3.0$
 * $Revision: 8$
 */
/**
 * Project InterMon v0.7.3
 */

#include "CmainServer.h"
#include "Cname.h"
#include "Cconfiguration.h"
#include "CserviceICMP.h"

const char __version__[] = "Project InterMon v0.7.3";

using namespace sqlite;
using namespace std;

#define MAXLINE 255
#define __TEST_DEVELOPING__ true

const char * charsTestConf[MAXLINE] = {
    "host", "name0",
    "ip", "0.0.0.0",
    "",
    "service", "icmp"
    "type", "8",
    "",
    "host", "host2",
    "ip", "2.2.2.2",
    "",
    nullptr
};

int main(int argc, char *argv[]) {
#if defined(DEBUG) && defined(PRINTM)
    printd("argc: ", argc, "; argv: ", argv) << endl;
#endif
#if defined(__TEST_DEVELOPING__)
    Cname testName;
    CserviceICMP srvICMP;
    testName.id = 0;
    testName.name = "testname";
    Cconfiguration nullConf();
    Cconfiguration zeroConf("/dev/zero");
    Cconfiguration testConf(charsTestConf);
    testConf.parse();
    CmainServer mainServer("test.xml");
    mainServer.init();
    mainServer.run();
#else
    CmainServer mainServer(charsTestConf);
    mainServer.init();
    mainServer.run();
#endif
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
