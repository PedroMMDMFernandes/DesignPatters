cmake_minimum_required(VERSION 3.10)

set(ABSTRACTFACTORY_SOURCES
    abstractFactory.cpp
)

set(ABSTRACTFACTORY_HEADERS
    abstractFactory.hpp
)

add_library(ABSTRACTFACTORY ${ABSTRACTFACTORY_SOURCES} ${ABSTRACTFACTORY_HEADERS})

target_include_directories(ABSTRACTFACTORY
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


