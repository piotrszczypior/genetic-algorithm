cmake_minimum_required(VERSION 3.25)
project(genetic-algorithm)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(genetic-algorithm src/main.cpp
        src/main.cpp
        src/algorithm/GeneticAlgorithm.cpp
        src/algorithm/GeneticAlgorithm.h
        src/file/FileReader.cpp
        src/file/FileReader.h
        src/model/Graph.cpp
        src/model/Graph.h
        src/model/CrossoverType.h
        src/menu/Menu.cpp
        src/model/AlgorithmConfig.h
        src/model/MutationType.h
        src/menu/Utils.cpp
        src/algorithm/model/Chromosome.h
        src/algorithm/model/Result.h
        src/file-writer/FileWriter.cpp)