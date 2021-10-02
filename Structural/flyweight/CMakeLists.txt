cmake_minimum_required(VERSION 3.10)

set(FLYWEIGHT_SOURCES
    flyweight.cpp
)

set(
    flyweight.hpp
)

add_library(FLYWEIGHT ${FLYWEIGHT_SOURCES} ${FLYWEIGHT_HEADERS})

target_include_directories(FLYWEIGHT
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS FLYWEIGHT DESTINATION lib)
install(FILES ${FLYWEIGHT_HEADERS} DESTINATION include)

