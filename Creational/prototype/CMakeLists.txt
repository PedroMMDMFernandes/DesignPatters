cmake_minimum_required(VERSION 3.10)

set(PROTOTYPE_SOURCES
    prototype.cpp
)

set(PROTOTYPE_HEADERS
    prototype.hpp
)

add_library(PROTOTYPE ${PROTOTYPE_SOURCES} ${PROTOTYPE_HEADERS})

target_include_directories(PROTOTYPE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


