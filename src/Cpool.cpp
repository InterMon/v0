/* $Id$
 * $Version: 0.8$
 * $Revision: 3$
 */
/**
 * Project InterMon $Version: 0.8
 */

// # define DEBUG 1

#if defined(DEBUG)
# include "mydebug.hpp"
#endif

#include <new>
#include <utility>
#include "Cpool.h"
#include "Cjob.h"

Cpool::Cpool(const Cpool && other)
: Sname(std::move(other)),
  _thread(std::move(other._thread)),
  _hosts(std::move(other._hosts))
{ _thread = nullptr; }

Cpool &
Cpool::operator=(const Cpool && right)
{
    if (this != &right) {
        Sname::operator=(right);
        _thread = nullptr;
    }
    return *this;
}

Cpool::~Cpool()
{
    if (nullptr != _thread) {
        delete _thread;
        _hosts.clear();
        _thread = nullptr;
    }
}

void
Cpool::addHost(Chost * host)
{
    _hosts.push_back(host);
}

void
Cpool::pushJob(Cjob && job)
{
    _jobs.push(std::move(job));
}

Cjob
Cpool::popJob()
{
    Cjob job = std::move(const_cast<Cjob&>(_jobs.top()));
    _jobs.pop();
    return std::move(job);
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
