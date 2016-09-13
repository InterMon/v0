/* $Id$
 * $Version: 0.7$
 */

#include "mydebug.hpp"

const char * em = "";
const char * & empty = em;
const char * sp = " ";
const char * & space = sp;
const char * cl = ":";
const char * & colon = cl;
const char * sc = ";";
const char * & semicolon = sc;
const std::string brackets[] = {"[", ",", "]"};
const std::string parens[] = {"(", ",", ")"};
const std::string (& parentheses)[3] = parens;
const std::string braces[] = {"{", ",", "}"};

/* vim: syntax=cpp:fileencoding=utf-8:fileformat=unix:tw=78:ts=4:sw=4:sts=4:et
 * EOF */
