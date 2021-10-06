cmake_minimum_required(VERSION 3.10)

set(TEMPLATE_SOURCES
    template.cpp
)

set(
    template.hpp
)

add_library(TEMPLATE ${TEMPLATE_SOURCES} ${TEMPLATE_HEADERS})

target_include_directories(TEMPLATE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS TEMPLATE DESTINATION lib)
install(FILES ${TEMPLATE_HEADERS} DESTINATION include)

