cmake_minimum_required(VERSION 3.10)

set(BRIDGE_SOURCES
    bridge.cpp
)

set(
    bridge.hpp
)

add_library(BRIDGE ${BRIDGE_SOURCES} ${BRIDGE_HEADERS})

target_include_directories(BRIDGE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS BRIDGE DESTINATION lib)
install(FILES ${BRIDGE_HEADERS} DESTINATION include)

