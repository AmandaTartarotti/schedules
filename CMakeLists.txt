cmake_minimum_required(VERSION 3.26)
project(schedules CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(schedules src/main.cpp src/ManageSchedule.h src/Student.h src/Student.cpp src/ManageSchedule.cpp)