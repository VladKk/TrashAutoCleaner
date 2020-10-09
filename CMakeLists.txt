cmake_minimum_required(VERSION 3.17)
project(TrashAutoCleaner LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(TrashAutoCleaner
        main.cpp
        daemon.h
        extra.h)