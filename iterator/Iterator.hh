/*
 * by Riley Shahar.
 *
 * Defines an `Iterator` concept implemented in line with the STL iterators, and
 * various methods on them.
 */

#include <cassert>
#include <concepts>

namespace iterator_concept {

/// Represents an abstract iterator.
///
/// Requires the type to implement a `begin` and an `end` method which yield the
/// same type and which we can increment and compare.
///
/// T is the type of the iterator (usually a sequential container), I is the
/// type it yields.
///
/// # Safety:
/// This concept, and many of its methods, assume that for an Iterator a,
/// a.end() is "after" a.begin(); that is, that
/// ```c++
/// for (auto it = iter.begin(); it != iter.end(); ++it);
/// ```
/// will deterministically terminate.
///
/// Similarly, it assumes that all the memory "between" `a.begin()` and
/// `a.end()` is valid; that is, that
/// ```c++
/// for (auto it = iter.begin(); it != iter.end(); +++it) {*it}
/// ```
/// is safe.
///
template <typename T, typename I>
concept Iterator = requires(T a, decltype(a.begin()) b, decltype(a.end()) e) {
  // begin and end must return the same type
  { *b }
  ->std::convertible_to<I>;
  { *e }
  ->std::convertible_to<I>;

  // we need to increment iterators
  {++b};

  // we need to compare iterators (to determine if an iterator is done):
  { b == e }
  ->std::same_as<bool>;
  { b != e }
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
/// assert (*iterator_concept::nth(std::vector<int>{1, 2, 3}, 2) == 3);
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
      // deference the iterator and get a reference to it
      // some of the stdlib iterators aren't std::convertible_to<*I>
      return &(*it);
    };
    i++;
  }
  // note this is more efficient than checking n < len(iter) before the loop
  // because len(iter) loops through the iterator anyway
  return nullptr;
}

} // namespace iterator_concept
