add_library(Iterator INTERFACE)
add_executable(test_iterator test_iterator.cpp)
target_link_libraries(test_iterator Iterator)
add_test(test_iterator test_iterator)

add_library(StringIter StringIter.cpp)
add_executable(test_stringiter test_stringiter.cpp)
target_link_libraries(test_stringiter StringIter Iterator)
add_test(test_stringiter test_stringiter)
