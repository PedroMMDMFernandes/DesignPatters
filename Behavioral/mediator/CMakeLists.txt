cmake_minimum_required(VERSION 3.10)

set(MEDIATOR_SOURCES
    mediator.cpp
)

set(
    mediator.hpp
)

add_library(MEDIATOR ${MEDIATOR_SOURCES} ${MEDIATOR_HEADERS})

target_include_directories(MEDIATOR
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS MEDIATOR DESTINATION lib)
install(FILES ${MEDIATOR_HEADERS} DESTINATION include)

