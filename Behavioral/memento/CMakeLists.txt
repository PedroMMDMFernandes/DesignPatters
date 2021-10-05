cmake_minimum_required(VERSION 3.10)

set(MEMENTO_SOURCES
    memento.cpp
)

set(MEMENTO_HEADERS
    memento.hpp
)

add_library(MEMENTO ${MEMENTO_SOURCES} ${MEMENTO_HEADERS})

target_include_directories(MEMENTO
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS MEMENTO DESTINATION lib)
install(FILES ${MEMENTO_HEADERS} DESTINATION include)

