cmake_minimum_required(VERSION 3.20)
project(SimSET2PETSIRD VERSION 0.4.0 LANGUAGES CXX)

find_package(SimSET 2.9.2 CONFIG REQUIRED)

find_package(PETSIRD REQUIRED CONFIG)

add_executable(SimSET_PETSIRD_convertor simset_petsird_convertor.cpp)
target_compile_features(SimSET_PETSIRD_convertor PRIVATE cxx_std_17)
target_link_libraries(SimSET_PETSIRD_convertor PRIVATE SimSET::simset PETSIRD::helpers)

if(MSVC)
  target_compile_options(SimSET_PETSIRD_convertor PRIVATE /W3 /WX)
else()
  target_compile_options(SimSET_PETSIRD_convertor PRIVATE -Wall)
endif()

install(TARGETS SimSET_PETSIRD_convertor DESTINATION bin)