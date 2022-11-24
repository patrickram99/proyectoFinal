cmake_minimum_required(VERSION 3.23)
project(proyectoFinal)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES
        *.h
        *.cpp
    )
add_executable(proyectoFinal ${SOURCE_FILES} ${SOURCES})


