cmake_minimum_required(VERSION 3.20)
project(TR1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/utils.cpp src/camada_fisica.cpp src/camada_app.cpp src/camada_enlace.cpp src/main.cpp)

add_executable(TR1 ${SOURCES})

target_include_directories(TR1 PRIVATE ${PROJECT_SOURCE_DIR}/inc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)