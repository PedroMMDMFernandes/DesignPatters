cmake_minimum_required(VERSION 3.10)

set(VISITOR_SOURCES
    visitor.cpp
)

set(
    visitor.hpp
)

add_library(VISITOR ${VISITOR_SOURCES} ${VISITOR_HEADERS})

target_include_directories(VISITOR
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS VISITOR DESTINATION lib)
install(FILES ${VISITOR_HEADERS} DESTINATION include)

