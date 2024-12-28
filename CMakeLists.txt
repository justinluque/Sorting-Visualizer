cmake_minimum_required(VERSION 3.16)
project(SortVisualizer)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "SortVisualizer Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for SortVisualizer
set(SortVisualizer_Version_Major 0)
set(SortVisualizer_Version_Minor 1)
set(SortVisualizer_Version_Patch 0)
set(SortVisualizer_Version_Status "-dev")
set(PROJECT_VERSION
  "${SortVisualizer_Version_Major}.${SortVisualizer_Version_Minor}.${SortVisualizer_Version_Patch}${SortVisualizer_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp BubbleSort.cpp SortingAlgorithm.cpp QuickSort.cpp Color3.cpp)

include_directories(
  /ucrt64/include
)

target_include_directories(${PROJECT_NAME} PRIVATE {SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
