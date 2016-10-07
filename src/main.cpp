/* $Id$
 * $Version: 0.8$
 * $Revision: 16$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "CmainServer.h"

#define MAXLINE 255
#define __TEST_DEVELOPING__ true

using namespace std;

#if defined(__TEST_DEVELOPING__)
# include "Acommand.h"
# include "Ccommand.h"
# include "CserviceICMP.h"
# define DEBUG 1
# include "mydebug.hpp"

class Cjob : public Cname {
public:
    Cjob() 
    { /* empty */
#if defined(DEBUG) && defined(PRINTM)
        printd("Cjob constructor, this: ", this) << std::endl;
#endif
    }
    Cjob(const Cjob & other)
    { /* empty */
#if defined(DEBUG) && defined(PRINTM)
        printd("Cjob copy constructor, this: ", this);
        printd("; &other: ", &other) << std::endl;
#endif
    }
    Cjob & operator=(const Cjob & other)
    {
#if defined(DEBUG) && defined(PRINTM)
        printd("Cjob  assignment operator this: ", this)
            << "; &other: " << &other << std::endl;
#endif
        return *this;
    }
    ~Cjob()
    { /* empty */ }
};

#endif

const char __version__[] = "Project InterMon $Version: 0.8";

int main(int argc, char *argv[])
{
#if defined(DEBUG) && defined(PRINTM)
    printd("argc: ", argc, "; argv: ", argv) << endl;
#endif
#if defined(__TEST_DEVELOPING__)

    Cjob job1;

    cout << "job1.name = " << job1.name << endl;
    job1.name = "job1";
    cout << "job1.name = " << job1.name << endl;
    Cjob job2;
    job2 = job1;

    CserviceICMP * srv = new CserviceICMP;
    Acommand * cmd = srv->getCheckCommand();

    cmd->execute();

    delete cmd;
    delete srv;

    /*
    CmainServer mainServer("test.xml");
    mainServer.init();
    mainServer.run(); */
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
