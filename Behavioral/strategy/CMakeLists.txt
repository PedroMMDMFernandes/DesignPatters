cmake_minimum_required(VERSION 3.10)

set(STRATEGY_SOURCES
    strategy.cpp
)

set(
    strategy .hpp
)

add_library(STRATEGY ${STRATEGY_SOURCES} ${STRATEGY_HEADERS})

target_include_directories(STRATEGY
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS STRATEGY DESTINATION lib)
install(FILES ${STRATEGY_HEADERS} DESTINATION include)

