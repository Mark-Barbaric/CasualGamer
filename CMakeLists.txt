cmake_minimum_required(VERSION 3.16)
project(Zuma)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
message("OpenCV Version ${OpenCV_Version}")

add_executable(Zuma main.cpp Objects/Ball.h Objects/ObjectColor.h)
target_link_libraries(Zuma ${OpenCV_LIBS})
