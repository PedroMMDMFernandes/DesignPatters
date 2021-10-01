cmake_minimum_required(VERSION 3.10)

set(FACADE_SOURCES
    facade.cpp
)

set(
    facade.hpp
)

add_library(FACADE ${FACADE_SOURCES} ${FACADE_HEADERS})

target_include_directories(FACADE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS FACADE DESTINATION lib)
install(FILES ${FACADE_HEADERS} DESTINATION include)

