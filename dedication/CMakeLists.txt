cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(dedication VERSION 0.0.1 LANGUAGES CXX)

add_executable(dedication
  main.cpp
)

set_property(TARGET dedication PROPERTY CXX_STANDARD 17)
