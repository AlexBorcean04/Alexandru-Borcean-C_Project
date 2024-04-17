cmake_minimum_required(VERSION 3.28)
project(Online_Shop C)

set(CMAKE_C_STANDARD 11)

add_executable(Online_Shop main.c
        user.h
        product.h
        order.h
        user.c
        product.c
        order.c
        bb.txt)
