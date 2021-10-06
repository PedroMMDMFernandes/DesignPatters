cmake_minimum_required(VERSION 3.10)

set(STATE_SOURCES
    state.cpp
)

set(
    state.hpp
)

add_library(STATE ${STATE_SOURCES} ${STATE_HEADERS})

target_include_directories(STATE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS STATE DESTINATION lib)
install(FILES ${STATE_HEADERS} DESTINATION include)

