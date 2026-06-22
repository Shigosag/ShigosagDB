cmake_minimum_required(VERSION 3.20)

project(ShigosagDB VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    shigosagdb

    src/main.cpp

    src/core/Database.cpp
    src/core/Table.cpp
    src/core/StorageEngine.cpp

    src/parser/Parser.cpp
    src/parser/Tokenizer.cpp

    src/utils/Logger.cpp
)
