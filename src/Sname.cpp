/* $Id$
 * $Version: 0.8$
 * $Revision: 15$
 */
/**
 * Project InterMon $Version: 0.8
 */

// # define DEBUG 1

#if defined(DEBUG)
# include "mydebug.hpp"
#endif

#include <iostream>
#include <utility>
#include "Sname.h"

Sname::Sname()
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Sname constructor, this:             ", this)
        << "; id: " << id << "; name: " << name
        << std::endl;
#endif
}

Sname::Sname(const Sname & other)
: Cid(other)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Sname copy constructor, this:        ", this)
        << "; id: " << id << "; name: " << name
        << "; &other: " << &other
        << std::endl;
#endif
    this->name = other.name;
}

Sname &
Sname::operator=(const Sname & right)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Sname assignment operator this:      ", this)
        << "; &right: " << &right << " ... ";
#endif
    if (this != &right) {
        this->name = right.name;
        std::cerr << "done.";
    }
    std::cerr << std::endl;
    return *this;
}

Sname::Sname(const Sname && other)
: Cid(std::move(other))
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Sname move constructor, this:        ", this)
        << "; &other: " << &other << std::endl;
#endif
    this->name = std::move(other.name);
}

Sname &
Sname::operator=(const Sname && right)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Sname move assignment operator this: ", this)
        << "; &right: " << &right << " ... ";
#endif
    if (this != &right) {
        // id = Cid::operator=(std::move(right));
        move(std::move(right));
        this->name = std::move(right.name);
        std::cerr << "done.";
    }
    return *this;
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
