/* $Id$
 * $Version: 7.4.0$
 * $Revision: 14$
 */
/**
 * Project InterMon $Version: 0.7.4
 */

#include "CserviceICMP.h"

CserviceICMP::CserviceICMP() {
    // TODO
}

CserviceICMP::~CserviceICMP() {
    // TODO
}

void CserviceICMP::checkCommand() {
#if defined(DEBUG) && defined(PRINTM)
    printd("service icmp check: ", _icmpType) << std::endl;
#endif
}

void CserviceICMP::notifyCommand() {
    // TODO
}

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
