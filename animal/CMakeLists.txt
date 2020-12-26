add_library(Animal INTERFACE)
add_executable(test_animal test_animal.cpp)
target_link_libraries(test_animal Animal)
