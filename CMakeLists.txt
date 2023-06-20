cmake_minimum_required(VERSION 3.25)
project(KMusicPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(KMusicPP src/main.cpp src/env_loader.cpp src/env_loader.h)
