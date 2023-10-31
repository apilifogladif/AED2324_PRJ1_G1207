cmake_minimum_required(VERSION 3.26)
project(AED2324_PRJ1_G1207)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AED2324_PRJ1_G1207
        main.cpp
        AuxiliarFunctions.cpp
        CsvAndVectors.cpp
        Lesson.cpp
        Request.cpp
        Schedule.cpp
        Student.cpp
        UC.cpp)
