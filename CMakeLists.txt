cmake_minimum_required(VERSION 3.17)
project(Library C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Library
        book.h
        customer.h
        data.h
        main.c
        queue.h
        )
