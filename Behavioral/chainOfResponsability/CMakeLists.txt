cmake_minimum_required(VERSION 3.10)

set(CHAINOFRESPONSABILITY_SOURCES
    chainOfResponsability.cpp
)

set(
    chainOfResponsability.hpp
)

add_library(CHAINOFRESPONSABILITY ${CHAINOFRESPONSABILITY_SOURCES} ${CHAINOFRESPONSABILITY_HEADERS})

target_include_directories(CHAINOFRESPONSABILITY
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS CHAINOFRESPONSABILITY DESTINATION lib)
install(FILES ${CHAINOFRESPONSABILITY_HEADERS} DESTINATION include)

