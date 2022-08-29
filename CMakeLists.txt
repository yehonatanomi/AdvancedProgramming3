cmake_minimum_required(VERSION 3.17.5)
project(client)
project(server)
set(CMAKE_CXX_STANDARD 14)

include_directories(x)

add_executable(server server.cpp x/distanceN.cpp x/flower.cpp x/Knn.cpp x/pointS.cpp )
add_executable(client client.cpp x/distanceN.cpp x/flower.cpp x/Knn.cpp x/pointS.cpp )