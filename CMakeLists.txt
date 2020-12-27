cmake_minimum_required(VERSION 3.17)

project(Animal)

# TODO: not all c++20 stdlibs ship with concepts, can we check for this?
set(CMAKE_CXX_STANDARD 20)  # concepts are in c++20
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
add_subdirectory(animal)

 
