/* $Id$
 * $Version: 0.6$
 */
/**
 * Project InterMon v0.6
 */

#include "CmainServer.h"
#include "Cname.h"
#include "Cconfiguration.h"
#include "CserviceICMP.h"

using namespace std;

#define MAXLINE 255
#define __TEST_DEVELOPING__ true

#if defined(__TEST_DEVELOPING__)
const char * charsTestConf[MAXLINE] = {
    "host", "localhost",
    "ip", "127.0.0.1",
    "",
    "service", "icmp"
    "type", "8",
    nullptr
};
#endif

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
    CmainServer mainServer(charsTestConf);
    mainServer.init();
#else
    CmainServer mainServer;
#endif
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
