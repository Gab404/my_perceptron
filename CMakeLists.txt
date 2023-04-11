cmake_minimum_required(VERSION 3.23)
project(my_perceptron C)

set(CMAKE_C_STANDARD 99)

add_executable(my_perceptron src/main.c src/getData.c src/gradient.c src/handleError.c src/loadNetwork.c src/mathFunction.c src/network.c src/saveWeights.c src/train.c)

target_link_libraries(my_perceptron)