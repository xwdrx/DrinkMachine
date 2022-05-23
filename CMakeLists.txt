cmake_minimum_required(VERSION 3.16)
project(DrinkMachine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DrinkMachine
        Automat.cpp
        Automat.h
        main.cpp
        Drink.cpp
        Drink.h
        Payment.cpp
        Payment.h
        Blik.h
        Blik.cpp
        Card.h
        Card.cpp
        readFile.h
        Exception.h
        Container.h)
