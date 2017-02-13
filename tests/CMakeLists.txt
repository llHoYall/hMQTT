cmake_minimum_required	(VERSION 2.6)
project	(hMQTT)

include_directories	(./ gtest)
add_subdirectory (gtest/src)

add_executable	(hMQTT_unittest main.cpp)
target_link_libraries (hMQTT_unittest gtest)

