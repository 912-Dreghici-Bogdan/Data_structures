cmake_minimum_required(VERSION 3.24)
project(Trial_2_of_lab_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Trial_2_of_lab_2
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        PriorityQueue.cpp
        PriorityQueue.h
        ShortTest.cpp
        ShortTest.h)
