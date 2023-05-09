cmake_minimum_required(VERSION 3.24)
project(Cproject C)

set(CMAKE_C_STANDARD 11)

add_executable(Cproject
        main.c shapes.h shapes.c point.h point.c line.h line.c square.h square.c rectangle.h rectangle.c circle.c polygon.h polygon.c id.c area.h area.c)
