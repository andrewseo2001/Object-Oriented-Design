cmake_minimum_required(VERSION 3.10)
project(ParkingLotProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    parking_lot
    parking_lot_demo.cpp
    parking_lot.cpp
    level.cpp
)