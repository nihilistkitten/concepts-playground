/*
 * by Riley Shahar
 *
 * Implementation of the StringIter class.
 */

#include "StringIter.hh"
#include <string>

namespace StringIter {
StringIter::StringIter(std::string s) : s{s} {}

char *StringIter::begin(void) { return &s[0]; }
char *StringIter::end(void) { return &s[s.size()]; }
} // namespace StringIter
