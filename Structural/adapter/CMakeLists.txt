cmake_minimum_required(VERSION 3.10)

set(ADAPTER_SOURCES
    adapter.cpp
)

set(
    adapter.hpp
)

add_library(ADAPTER ${ADAPTER_SOURCES} ${ADAPTER_HEADERS})

target_include_directories(ADAPTER
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS ADAPTER DESTINATION lib)
install(FILES ${ADAPTER_HEADERS} DESTINATION include)

