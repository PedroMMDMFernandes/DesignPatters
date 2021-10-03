cmake_minimum_required(VERSION 3.10)

set(SINGLETON_SOURCES
    singleton.cpp
)

set(
    singleton.hpp
)

add_library(SINGLETON ${SINGLETON_SOURCES} ${SINGLETON_HEADERS})

target_include_directories(SINGLETON
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS SINGLETON DESTINATION lib)
install(FILES ${SINGLETON_HEADERS} DESTINATION include)

