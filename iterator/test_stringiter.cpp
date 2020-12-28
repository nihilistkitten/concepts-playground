/*
 * by Riley Shahar
 *
 * Tests for `StringIter.hh`.
 */

#include "Iterator.hh"
#include "StringIter.hh"
#include <cassert>

int main(void) {
  StringIter::StringIter s = StringIter::StringIter("Hello, world!");
  assert(iterator_concept::len<char>(s) == 13);
  assert(*iterator_concept::nth<char>(s, 5) == ',');

  StringIter::StringIter empty = StringIter::StringIter("");
  assert(iterator_concept::len<char>(empty) == 0);
}
