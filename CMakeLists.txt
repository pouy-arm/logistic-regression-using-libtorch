cmake_minimum_required(VERSION 3.28)
project(tensor)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_PREFIX_PATH /home/pouyan/libs/libtorch/)
find_package(Torch REQUIRED)
add_executable(tensor main.cpp)
target_link_libraries(tensor "${TORCH_LIBRARIES}")