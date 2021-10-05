cmake_minimum_required(VERSION 3.10)

#set project name and version
project(DesignPatterns)

#specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#specify sources
set(DESIGNPATTERNS_SOURCES 
    main.cpp
)

option(USE_SINGLETON "Use singleton Design Pattern" ON)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Creational)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Structural)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Behavioral)

if(USE_SINGLETON)
    
endif(USE_SINGLETON)


add_executable(${PROJECT_NAME} ${DESIGNPATTERNS_SOURCES})



target_include_directories(DesignPatterns PRIVATE
                           "${PROJECT_BINARY_DIR}"
                           Creational
                           )

target_link_libraries(${PROJECT_NAME} PUBLIC 
    SINGLETON 
    PROTOTYPE 
    FACTORY
    BUILDER
    ABSTRACTFACTORY
    ADAPTER
    BRIDGE
    COMPOSITE
    DECORATOR
    FACADE
    FLYWEIGHT
    PROXY
    CHAINOFRESPONSABILITY
    COMMAND
    ITERATOR
    MEDIATOR
    MEMENTO
)

#specify install Target
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

#specify testing
#enable_testing()

add_test(NAME Runs COMMAND ${PROJECT_NAME} 25)

add_test(NAME Usage COMMAND ${PROJECT_NAME})

set_tests_properties(Usage 
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage:-*number"    
)

#define funtion to simplify adding tests

function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg} )
    set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()
