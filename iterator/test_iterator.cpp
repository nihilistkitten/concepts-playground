/*
 * by Riley Shahar
 *
 * Tests for `Iterator.hh`.
 */

#include "Iterator.hh"
#include <cassert>
#include <deque>
#include <string>
#include <vector>

int main(void) {
  std::vector<int> vec = std::vector{1, 2, 3};
  assert(iterator_concept::len<int>(vec));
  assert(*iterator_concept::nth<int>(vec, 2) == 3);
  assert(iterator_concept::nth<int>(vec, 3) == nullptr);

  std::deque<int> queue = std::deque{1, 2, 3};
  assert(iterator_concept::len<int>(queue));
  assert(*iterator_concept::nth<int>(queue, 2) == 3);
  assert(iterator_concept::nth<int>(queue, 3) == nullptr);

  std::string s = "Hello, world!";
  assert(iterator_concept::len<char>(s) == 13);
  assert(*iterator_concept::nth<char>(s, 5) == ',');
}
