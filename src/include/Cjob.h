/* $Id$
 * $Version: 0.8$
 * $Revision: 4$
 */
/**
 * Project InterMon $Version: 0.8
 */

#pragma once
#ifndef _C_JOB_H
#define _C_JOB_H

#include <ctime>
#include <cmath>
#include "Sname.h"
#include "Acommand.h"
#include "Aservice.h"

#define SHIFT 3

class Cjob : public Sname {
private:
    Aservice * _service;
    Acommand * _command;
    time_t     _deadline;
public:
    Cjob() = delete;
    Cjob(Aservice * srv, Acommand * cmd);
    Cjob(const Cjob & other);
    Cjob & operator=(const Cjob & right);
    Cjob(Cjob&& other) noexcept;
    Cjob & operator=(Cjob && right);
    void setDeadline();

    const Aservice * service() const {
        return _service;
    }

    const Acommand * command() const {
        return _command;
    }

    bool isCommandNull() const {
        return nullptr == _command;
    }

    void execute() const {
        if (nullptr != _command)
            _command->execute();
    }

    bool isServiceNull() const {
        return nullptr == _service;
    }

    time_t getDeadline() const {
        return _deadline;
    }

    void setDeadline(time_t t) {
        _deadline = t;
    }

    /**
     * Destructor
     */
    ~Cjob() {
        _service = nullptr;
        _command = nullptr;
    };
};

namespace std {
    template <>
    struct less<Cjob>
    {
        bool operator()(const Cjob& x, const Cjob& y) const;
        typedef Cjob first_argument_type;
        typedef Cjob second_argument_type;
        typedef bool result_type;
    };
}

#endif //_C_JOB_H

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
