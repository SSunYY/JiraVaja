cmake_minimum_required(VERSION 3.26)
project(Naloga7_1_PointPrimer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Naloga7_1_PointPrimer
        "Point (1).cpp"
        Point.h
        LinearQueue.h)
