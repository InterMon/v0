/* $Id$
 * $Version: 0.0$
 * $Revision: 6$
 */
/**
 * Project InterMon $Version: 0.0
 */

#pragma once
#ifndef _C_POOL_H
#define _C_POOL_H

#include <queue>
#include <vector>
#include <thread>
#include "Sname.h"
#include "Cjob.h"
#include "Chost.h"

class Cpool : public Sname {
private:
    typedef std::vector<Chost*> SetOfHosts;
    std::thread *               _thread;
    SetOfHosts                  _hosts;
    std::priority_queue<Cjob>   _jobs;
public:
    Cpool() : _thread(nullptr) { /* Empty */ }
    Cpool(const Cpool & other) = delete;
    Cpool & operator=(const Cpool & other) = delete;

    Cpool(const Cpool && other);
    Cpool & operator=(const Cpool && right);

    void addHost(Chost * host);
    void pushJob(Cjob && job);
    Cjob popJob();

    bool isJobsEmpty() {
        return _jobs.empty();
    }

    const Cjob & topOfJobs() {
        return _jobs.top();
    }

    void newThread(std::thread * thread) {
        _thread = thread;
    }

    void threadJoin() {
        _thread->join();
    }

    /* */
    friend class ChostsIterator;

    class ChostsIterator: public Aiterator<SetOfHosts::value_type> {
        friend class Cpool;
    private:
        Cpool::SetOfHosts &         _hosts;
        Cpool::SetOfHosts::iterator _itr;
        ChostsIterator(Cpool::SetOfHosts & hosts)
        : _hosts(hosts), _itr(_hosts.begin()) { /* Empty */ }
    public:
        virtual bool hasNext() {
            return _itr != _hosts.end();
        }
        virtual ChostsIterator::value_type next(void) {
            ChostsIterator::value_type value = (*_itr);
            ++_itr;
            return value;
        }
    };

    /* */
    ChostsIterator getHostsIterator() {
        return ChostsIterator(_hosts);
    }

    /**
     * Destructor
     */
    ~Cpool();
};

#endif //_C_POOL_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
