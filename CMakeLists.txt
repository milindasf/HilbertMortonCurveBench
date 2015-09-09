project(hilbertcurvebench)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(hilbertcurvebench src/rotation.cpp src/sfc.cpp src/dendro.cpp src/hilbert.cpp src/morton.cpp src/point.cpp src/benchmark.cpp main.cpp )

install(TARGETS hilbertcurvebench RUNTIME DESTINATION bin)
add_subdirectory(src)
add_subdirectory(include)