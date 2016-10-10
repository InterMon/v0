/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 5$
=======
 * $Revision: 4$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

// # define DEBUG 1

#if defined(DEBUG)
# include "mydebug.hpp"
#endif

#include <ctime>
#include <utility>
extern "C" {
# include "cpue.h"
}
#include "Cjob.h"

Cjob::Cjob(Aservice * srv, Acommand * cmd)
: _service(srv),
  _command(cmd),
  _deadline(time(nullptr))
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cjob spec constructor, this: ", this)
        << "; id: " << id << std::endl;
#endif
}

Cjob::Cjob(const Cjob & other)
: Sname(other),
  _service(other._service),
  _command(other._command),
  _deadline(other._deadline)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cjob copy constructor, this: ", this)
        << "; &other: " << &other
        << "; id: " << id << std::endl;
#endif
}

Cjob &
Cjob::operator=(const Cjob & right) {
#if defined(DEBUG) && defined(PRINTM)
    printd("Cjob assignment operator this: ", this)
        << "; &right: " << &right
        << "; id: " << id << std::endl;
#endif
    if (this != &right) {
        Sname::operator=(right);
        _service = right._service;
        _command = right._command;
        _deadline = right._deadline;
    }
    return *this;
}

Cjob::Cjob(Cjob&& other) noexcept
: Sname(std::move(other)),
  _service(std::move(other._service)),
  _command(std::move(other._command)),
  _deadline(std::move(other._deadline)) {
#if defined(DEBUG) && defined(PRINTM)
    printd("Cjob move constructor, this: ", this)
        << "; &other: " << &other
        << "; id: " << id << std::endl;
#endif
    other._service = nullptr;
    other._command = nullptr;
    other._deadline = epoch();
}

Cjob &
Cjob::operator=(Cjob && right) {
#if defined(DEBUG) && defined(PRINTM)
    printd("Cjob move assignment operator this: ", this)
        << "; &right: " << &right
        << "; id: " << id << std::endl;
#endif
    // this may be called once or twice
    // if called twice, 'other' is the just-moved-from V subobject
    if (this != &right) {
        Sname::operator=(std::move(right));
        _service = right._service;
        _command = right._command;
        _deadline = right._deadline;
        right._service = nullptr;
        right._command = nullptr;
        right._deadline = epoch();
    }
    return *this;
}

void
Cjob::setDeadline()
{
    if (isServiceNull() or isCommandNull())
        return;
    time_t now = time(nullptr);
    struct tm shedule_to;
    shedule_to = *localtime(&now);
    shedule_to.tm_min += _service->getCheckInterval();
    if ((59 - SHIFT - 1) < shedule_to.tm_sec) {
        shedule_to.tm_sec += SHIFT;
    } else {
        shedule_to.tm_min++;
        shedule_to.tm_sec = SHIFT;
    }
    _deadline = mktime(&shedule_to);
}

bool
std::less<Cjob>::operator()(const Cjob& x, const Cjob& y)
const
{
    time_t x_time = x.getDeadline();
    time_t y_time = y.getDeadline();
    double diff = difftime(x_time, y_time);
    if (std::abs(diff) < 1E-14)
        return y.id < x.id;
    if (0.0 < diff)
        return true;
    return false;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
