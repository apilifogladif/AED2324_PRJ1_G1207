cmake_minimum_required(VERSION 3.26)
project(AED2324_PRJ1_G1207)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AED2324_PRJ1_G1207
        AuxiliarFunctions.cpp
        AuxiliarFunctions.h
        CsvAndVectors.cpp
        Lesson.cpp
        Lesson.h
        main.cpp
        Request.cpp
        Request.h
        Schedule.cpp
        Schedule.h
        Student.cpp
        Student.h
        terminal.cpp
        UC.cpp
        UC.h)
