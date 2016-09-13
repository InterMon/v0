/* $Id$
 * $Version: 0.5$
 */
/**
 * Project InterMon v0.5
 */

#include "Cname.h"
#include "Cconfiguration.h"
#include "CserviceICMP.h"

int main(int argc, char *argv[]) {
    Cname testName;
    CserviceICMP srvICMP;
    testName.id = 0;
    testName.name = "testname";
    Cconfiguration nullConf();
    Cconfiguration conf("/dev/zero");
    return 0;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
