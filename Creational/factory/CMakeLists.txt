cmake_minimum_required(VERSION 3.10)

set(FACTORY_SOURCES
    factory.cpp
)

set(FACTORY_HEADERS
    factory.hpp
)

add_library(FACTORY ${FACTORY_SOURCES} ${FACTORY_HEADERS})

target_include_directories(FACTORY
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


