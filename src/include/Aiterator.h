/* $Id$
 * $Version: 0.8$
<<<<<<< HEAD
 * $Revision: 3$
=======
 * $Revision: 2$
>>>>>>> 11728d58400cb78f0f0e3cef88845c3333bf47e4
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _AITERATOR_H
#define _AITERATOR_H

template<typename T>
class Aiterator {
public:
    typedef T value_type;
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

#endif //_AITERATOR_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
