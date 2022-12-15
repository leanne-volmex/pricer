cmake_minimum_required(VERSION 3.12)
project(threadtest)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost)
add_executable(bs bs.cpp)
target_link_libraries(bs Boost::boost)