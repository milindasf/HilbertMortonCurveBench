#cmake_minimum_required(VERSION 3.3)
project(HilbertCurveBench)

#add_subdirectory(src)
#add_subdirectory(include)

option(DENDRO_DIM2 "Use dendro in 2D" ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(hilbertcurvebench src/rotation.cpp src/sfc.cpp src/dendro.cpp src/hilbert.cpp src/morton.cpp src/point.cpp src/benchmark.cpp src/hcurvedata.cpp main.cpp include/hcurvedata.h )

