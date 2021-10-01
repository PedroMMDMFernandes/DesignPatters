cmake_minimum_required(VERSION 3.10)

set(COMPOSITE_SOURCES
    composite.cpp
)

set(
    composite.hpp
)

add_library(COMPOSITE ${COMPOSITE_SOURCES} ${COMPOSITE_HEADERS})

target_include_directories(COMPOSITE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS COMPOSITE DESTINATION lib)
install(FILES ${COMPOSITE_HEADERS} DESTINATION include)

