cmake_minimum_required(VERSION 3.31)
project(koshelieva_a_plpp_assignment3)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR})

add_library(MyDll SHARED
        ceasar.cpp
)

add_executable(koshelieva_a_plpp_assignment3 main.cpp
        ceasar.cpp
        ceasar.h)

target_link_libraries(koshelieva_a_plpp_assignment3 PRIVATE MyDll)

set_target_properties(koshelieva_a_plpp_assignment3 PROPERTIES
WIN32_EXECUTABLE FALSE
)

target_compile_definitions(MyDll PRIVATE BUILD_DLL)