cmake_minimum_required(VERSION 3.25)
project(Pixel_Tracer_main C)

set(CMAKE_C_STANDARD 11)

include_directories(Pixel-Tracer-main)

add_executable(Pixel_Tracer_main
        Pixel-Tracer-main/area.c
        Pixel-Tracer-main/area.h
        Pixel-Tracer-main/circle.c
        Pixel-Tracer-main/circle.h
        Pixel-Tracer-main/commands.c
        Pixel-Tracer-main/commands.h
        Pixel-Tracer-main/id.c
        Pixel-Tracer-main/id.h
        Pixel-Tracer-main/line.c
        Pixel-Tracer-main/line.h
        Pixel-Tracer-main/main.c
        Pixel-Tracer-main/pixel.c
        Pixel-Tracer-main/pixel.h
        Pixel-Tracer-main/point.c
        Pixel-Tracer-main/point.h
        Pixel-Tracer-main/polygon.c
        Pixel-Tracer-main/polygon.h
        Pixel-Tracer-main/rectangle.c
        Pixel-Tracer-main/rectangle.h
        Pixel-Tracer-main/shapes.c
        Pixel-Tracer-main/shapes.h
        Pixel-Tracer-main/square.c
        Pixel-Tracer-main/square.h)
