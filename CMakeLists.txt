# License: MIT. See LICENSE in root directory.
# Date: 2020/06/26

cmake_minimum_required(VERSION 3.1.0)

project("ensemble-managed-array" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("${CMAKE_CURRENT_LIST_DIR}/inc")

add_compile_definitions("ENSEMBLE_MANAGED_ARRAY_VERSION=1")
set(ENSEMBLE_MANAGED_ARRAY_LIB "ensemble-managed-array-lib")
add_library(${ENSEMBLE_MANAGED_ARRAY_LIB} STATIC "")
target_sources(
    ${ENSEMBLE_MANAGED_ARRAY_LIB}
    PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/src/ensemble/managed-array.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/inc/ensemble/managed-array.hpp"
)

if (CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
    set(ENSEMBLE_MANAGED_ARRAY_EXE "ensemble-managed-array-exe")
    add_executable(${ENSEMBLE_MANAGED_ARRAY_EXE} "${CMAKE_CURRENT_LIST_DIR}/test/main.cpp")
    target_link_libraries(${ENSEMBLE_MANAGED_ARRAY_EXE} ${ENSEMBLE_MANAGED_ARRAY_LIB})
endif ()
