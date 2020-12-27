/*
 * by Riley Shahar
 *
 * Tests for `Iterator.hh`.
 */

#include "Iterator.hh"
#include <cassert>
#include <vector>

int main(void) {
  std::vector<int> vec = std::vector{1, 2, 3};
  assert(iterator_concept::len<int>(vec));
  assert(*iterator_concept::nth<int>(vec, 2) == 3);
  assert(iterator_concept::nth<int>(vec, 3) == nullptr);
}
