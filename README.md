# logistic-regression-using-libtorch

### overview

The program fits a cubic polynomial to the sine function using 2000 data points and 2000 iterations of gradient descent. The goal is to minimize the mean squared error (MSE) between the predicted polynomial and the actual sine values.

### Installation

The code uses standard C++ libraries. Make sure that you have the c++ compiler:
- **Linux Ubuntu**: Install `g++` with `sudo apt install g++` and verify with `g++ --version`.
- **Linux Manjaro**: Install `g++` with `sudo pacman -S gcc` and verify with `g++ --version`.

### Run the Code

To compile and run the code:
- Save the C++ code in a file named main.cpp.
- Create a build directory: `mkdir build` then `cd build`
- Generate build files using CMake: `cmake ..`
- Compile the code: `make`
- Run the code: `./fileName`
The program will output the MSE every 100 iterations and the final cubic polynomial equation

### CMake File

Create a **CMakeLists.txt** file in the project directory with the following content:
- cmake_minimum_required(VERSION 3.28)
- project(tensor)
- set(CMAKE_CXX_STANDARD 20)
- list(APPEND CMAKE_PREFIX_PATH /home/pouyan/libs/libtorch/)
- find_package(Torch REQUIRED)
- add_executable(tensor main.cpp)
- target_link_libraries(tensor "${TORCH_LIBRARIES}")

(The input of the project and add_executable will change according to different people project and file namings.)