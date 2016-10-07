/* $Id$
 * $Version: 0.8$
 * $Revision: 12$
 */
/**
 * Project InterMon $Version: 0.8
 */

#include "Ccommand.h"
#include "CserviceSNMPGet.h"

CserviceSNMPGet::CserviceSNMPGet()
{
    // TODO
}

CserviceSNMPGet::~CserviceSNMPGet()
{
    // TODO
}

void
CserviceSNMPGet::checkCommand()
{
    // TODO
}

void
CserviceSNMPGet::notifyCommand()
{
    // TODO
}

Acommand *
CserviceSNMPGet::getCheckCommand()
throw(std::bad_alloc)
{
    return new Ccommand<CserviceSNMPGet>(this, &CserviceSNMPGet::checkCommand);
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
