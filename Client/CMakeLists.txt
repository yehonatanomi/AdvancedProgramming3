cmake_minimum_required(VERSION 2.8.12.2)

project(Client)
find_package(Threads)

add_executable(Client main.cpp ../tools.h ../tools.cpp TClient.cpp TClient.h)

target_link_libraries(Client ${CMAKE_THREAD_LIBS_INIT})