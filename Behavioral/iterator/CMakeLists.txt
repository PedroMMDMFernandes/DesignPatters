cmake_minimum_required(VERSION 3.10)

set(ITERATOR_SOURCES
    iterator.cpp
)

set(
    iterator.hpp
)

add_library(ITERATOR ${ITERATOR_SOURCES} ${ITERATOR_HEADERS})

target_include_directories(ITERATOR
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS ITERATOR DESTINATION lib)
install(FILES ${ITERATOR_HEADERS} DESTINATION include)

