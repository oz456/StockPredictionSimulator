cmake_minimum_required(VERSION 3.5)
project(StockPredictor)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR})

file(GLOB SRC_FILES "src/*.cpp")
add_executable(StockPredictor ${SRC_FILES})
target_link_libraries(StockPredictor pthread)
