cmake_minimum_required(VERSION 3.27)
project(chessboard_with_qt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


qt_add_executable(problem04 chessboard.cpp)


target_link_libraries(problem04 PRIVATE Qt6::Widgets)

