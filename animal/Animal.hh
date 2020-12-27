/*
 * A simple `Animal` concept which requires a single `noise` method. This
 * library is just to practice/demonstrate the basic template syntax.
 *
 * by Riley Shahar
 *
 */

#include <concepts>
#include <iostream>
#include <string>

// Something with an associated noise
template <typename T> concept Animal = requires(T a) {
  { a.noise() }
  ->std::same_as<std::string>;
};

// Make an animal's noise twice
void make_noise_twice(Animal auto a) {
  std::cout << a.noise();
  std::cout << a.noise();
}
