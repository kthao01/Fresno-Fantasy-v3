cmake_minimum_required(VERSION 3.26)
project(FresnoFantasy_v3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FresnoFantasy_v3
        Effect.cpp
        Effect.h
        Fighter.cpp
        Fighter.h
        main.cpp
        Player.cpp
        Player.h
        Rogue.cpp
        Rogue.h)
