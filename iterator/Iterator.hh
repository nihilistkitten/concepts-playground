/*
 * by Riley Shahar.
 *
 * Defines an `Iterator` concept implemented in line with the STL iterators, and
 * various methods (mostly adapted from the Rust standard library) on them.
 *
 * See https://doc.rust-lang.org/std/iter/trait.Iterator.html for the source
 * that I'm adapting many of these methods from.
 */

#include <cassert>
#include <concepts>

namespace iterator_concept {

/// Represents an abstract iterator.
///
/// Requires the type to implement a `begin` and an `end` method which yield the
/// same type and which we can increment and compare.
///
template <typename T, typename I> concept Iterator = requires(T a) {

  // begin and end must return the same type
  { *a.begin() }
  ->std::convertible_to<I>;
  { *a.end() }
  ->std::convertible_to<I>;

  // we need to increment iterators
  {++(a.begin())};

  // we need to compare iterators (to determine if an iterator is done):
  { a.begin() == a.begin() }
  ->std::same_as<bool>;
  { a.begin() != a.begin() }
  ->std::same_as<bool>;
};

/// Calculate the length of an iterator.
///
/// # Examples
/// ```c++
/// assert (iterator_concept::len(std::vector<int>{1, 2, 3}) == 3);
/// ```
///
/// # Safety
/// Triggers UB (an interger overflow) if the length is bigger than `INT_MAX`.
///
template <typename I, Iterator<I> T> I len(T iter) {
  int out = 0;
  for (auto it = iter.begin(); it != iter.end(); ++it) {
    out += 1;
  }
  return out;
};

/// Return a pointer to the nth element of an iterator, or `nullptr` otherwise.
///
/// # Examples
/// ```c++
/// assert (*iterator_concept::nth(std::vector<int>{1, 2, 3}, 2) == 3);```
/// ```
///
/// ```c++
/// assert (iterator_concept::nth(std::vector<int>{1, 2, 3}, 3) == nullptr);
/// ```
///
/// # Safety
/// Crashes if `n < 0`.
///
template <typename I, Iterator<I> T> I *nth(T iter, int n) {
  assert(n >= 0);
  int i = 0;
  for (auto it = iter.begin(); it != iter.end(); ++it) {
    if (i == n) {
      return &(*it);
    };
    i++;
  }
  return nullptr;
}

} // namespace iterator_concept
