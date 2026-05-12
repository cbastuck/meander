cmake_minimum_required(VERSION 3.21)
project(hkp LANGUAGES CXX VERSION 1.0)

if(APPLE)
	enable_language(OBJCXX)
endif()

add_subdirectory(3rdparty)
add_subdirectory(hkp-rt)
add_subdirectory(meander)
