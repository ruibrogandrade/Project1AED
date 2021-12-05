cmake_minimum_required(VERSION 3.20)
project(AED_project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_project1 main.cpp Tests/avião.cpp Tests/avião.h Tests/voo.cpp Tests/voo.h Tests/passageiro.cpp Tests/passageiro.h)
