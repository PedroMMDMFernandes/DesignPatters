cmake_minimum_required(VERSION 3.10)

set(BUILDER_SOURCES
    builder.cpp
)

set(BUILDER_HEADERS
    builder.hpp
)

add_library(BUILDER ${BUILDER_SOURCES} ${BUILDER_HEADERS})

target_include_directories(BUILDER
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


