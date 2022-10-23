cmake_minimum_required(VERSION 3.10)

set(COMMAND_SOURCES
    command.cpp
)

set(
    command.hpp
)

add_library(COMMAND ${COMMAND_SOURCES} ${COMMAND_HEADERS})

target_include_directories(COMMAND
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS COMMAND DESTINATION lib)
install(FILES ${COMMAND_HEADERS} DESTINATION include)

