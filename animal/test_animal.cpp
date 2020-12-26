/*
 * Test code for `Animal.hh`
 *
 * by Riley Shahar
 *
 */

#include "Animal.hh"
#include "string"

class Dog {
public:
  std::string noise() { return "bark"; }
};

class Cat {
public:
  std::string noise() { return "meow"; }
};

int main(void) {
  Dog d = Dog{};
  make_noise_twice(d);
}
