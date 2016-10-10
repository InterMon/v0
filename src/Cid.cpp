/* $Id$
 * $Version: 0.8$
 * $Revision: 14$
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
#include "Cid.h"

long long Cid::seq = 0;

Cid::Cid()
: id(++seq)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid constructor, this: ", this) << std::endl;
#endif
}

Cid::Cid(const Cid & other)
: id(++seq)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid copy constructor, this: ", this)
        << "; &other: " << &other << std::endl;
#endif
}

Cid &
Cid::operator=(const Cid & right)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid assignment operator this: ", this)
        << "; &right: " << &right << " ... ";
#endif
    if (this != &right) {
        this->~Cid();
        new (this) Cid(right);
#if defined(DEBUG) && defined(PRINTM)
        std::cerr << "done.";
    }
    std::cerr << std::endl;
#else
    }
#endif
    return *this;
}

Cid::Cid(const Cid && other)
: id(std::move(other.id))
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid move constructor, this: ", this)
        << "; &other: " << &other << " ... ";
#endif
    if (this != &other) {
        this->~Cid();
        new (this) Cid(other.id);

#if defined(DEBUG) && defined(PRINTM)
        std::cerr << "done.";
    }
    std::cerr << std::endl;
#else
    }
#endif
}

Cid &
Cid::operator=(const Cid && right)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid move assignment operator this: ", this)
        << "; &right: " << &right << " ... ";
#endif
    if (this != &right) { 
        this->~Cid();
        new (this) Cid(right.id);
#if defined(DEBUG) && defined(PRINTM)
        std::cerr << "done.";
    }
    std::cerr << std::endl;
#else
    }
#endif
    return *this;
}

void
Cid::move(const Cid && right)
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid move function this: ", this)
        << "; &right: " << &right << " ... ";
#endif
    if (this != &right) { 
        this->~Cid();
        new (this) Cid(right.id);
#if defined(DEBUG) && defined(PRINTM)
        std::cerr << "done.";
    }
    std::cerr << std::endl;
#else
    }
#endif
}

Cid::~Cid()
{
#if defined(DEBUG) && defined(PRINTM)
    printd("Cid destructor, this: ", this) << std::endl;
#endif
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
