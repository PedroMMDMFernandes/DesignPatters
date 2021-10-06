cmake_minimum_required(VERSION 3.10)

set(OBSERVER_SOURCES
    observer.cpp
)

set(
    observer.hpp
)

add_library(OBSERVER ${OBSERVER_SOURCES} ${OBSERVER_HEADERS})

target_include_directories(OBSERVER
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS OBSERVER DESTINATION lib)
install(FILES ${OBSERVER_HEADERS} DESTINATION include)

