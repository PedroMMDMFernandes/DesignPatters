cmake_minimum_required(VERSION 3.10)

set(PROXY_SOURCES
    proxy.cpp
)

set(
    proxy.hpp
)

add_library(PROXY ${PROXY_SOURCES} ${PROXY_HEADERS})

target_include_directories(PROXY
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS PROXY DESTINATION lib)
install(FILES ${PROXY_HEADERS} DESTINATION include)

