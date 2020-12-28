/*
 * by Riley Shahar
 *
 * A simple class which iterates over the characters of a string.
 */

#include <string>
// note that we don't need to include Iterator.hh

namespace StringIter {

/// Iterates over the characters of a string.
class StringIter {
private:
  std::string s;

public:
  StringIter(std::string s);
  char *begin();
  char *end();
};
} // namespace StringIter
