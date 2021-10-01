cmake_minimum_required(VERSION 3.10)

set(DECORATOR_SOURCES
    decorator.cpp
)

set(
    decorator.hpp
)

add_library(DECORATOR ${DECORATOR_SOURCES} ${DECORATOR_HEADERS})

target_include_directories(DECORATOR
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS DECORATOR DESTINATION lib)
install(FILES ${DECORATOR_HEADERS} DESTINATION include)

