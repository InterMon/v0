/* $Id$
 * $Version: 0.8$
 * $Revision: 21$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "CmainServer.h"

using namespace std;

#if defined(__TEST_DEVELOPING__)
# include <functional>
# include "Acommand.h"
# include "Ccommand.h"
# include "CserviceICMP.h"
# include "Cjob.h"
 extern "C" {
# include "cpue.h"
 }
# define DEBUG 1
# include "mydebug.hpp"

Cjob test(Cjob test) {
    cout << "test.name = " << test.name << " test.id = " << test.id << endl;
    test.name = "test";
    return test;
}

void coutDeadline(const Cjob & j) {
  time_t now = j.getDeadline();
  struct tm * timeinfo;
  timeinfo = localtime(&now);
  cout << "j.name: " << j.name
       << " j.getDeadline(): " << asctime(timeinfo)
       << endl;
}

#endif

const char __version__[] = "Project InterMon $Version: 0.8";

int main(int argc, char *argv[])
{
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
