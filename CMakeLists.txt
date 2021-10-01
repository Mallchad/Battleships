# GPL3 License
# Copyright (c) 2021 Mallchad
# This source provides the right to be freely used in any form, so long as modified
# variations remain available publically, or open request.
# Modified versions must be marked as such.
# The source comes with no warranty of any kind.

cmake_minimum_required(VERSION 3.10)

project(battleships VERSION 1.0
  LANGUAGES CXX)

# Build Calls


# Core
add_executable(battleships "battleshipsFinal/main.cpp"
                       "battleshipsFinal/Player.cpp"
                       "battleshipsFinal/GameManager.cpp"
                       "battleshipsFinal/InputManager.cpp"
                       "battleshipsFinal/DisplayManager.cpp"
                       "battleshipsFinal/mallib.cpp")
target_compile_definitions(battleships PUBLIC BATTLESHIPS_DEBUG=${BATTLESHIPS_DEBUG})
target_include_directories(battleships PUBLIC "battleshipsFinal/")

# Dependencies
# add_library(<dependency_name> STATIC include)

# Functions

function(set_default variable value)
  if(NOT DEFINED variable)
    set(variable value)
  endif()
endfunction()

# Variables
set_default(BATTLESHIPS_MINIMUM_CXX_STANDARD 11
  CACHE STRING "The minimum C++ Standard to use")
set_default(BATTLESHIPS_BUILD_TYPE ${CMAKE_BUILD_TYPE}
  CACHE STRING "The type of build the battleships wants to make")
set_default(BATTLESHIPS_BUILD_DIR ${CMAKE_BINARY_DIR}
  CACHE STRING "A custom path for the build directory")
set_default(BATTLESHIPS_BINARY_DIR ${BATTLESHIPS_BUILD_DIR}/bin
  CACHE STRING "A custom path for the binary output directory")
set_default(BATTLESHIPS_LIBRARY_DIR ${BATTLESHIPS_BUILD_DIR}/lib
  CACHE STRING "A custom path for the library output directory")
set_default(BATTLESHIPS_ARTIFACT_DIR ${BATTLESHIPS_BUILD_DIR}/artifacts
  CACHE STRING "A custom path for the build artifact output directory")
set_default(BATTLESHIPS_DEBUG_DIR ${BATTLESHIPS_BUILD_DIR}/debug
  CACHE STRING "A custom path for the build artifact output directory")
set_default(BATTLESHIPS_ENABLE_DEBUG 1
  CACHE STRING "Enables debugging specific options")
set_default(BATTLESHIPS_USE_CCACHE 1
  CACHE STRING "Whether to prioritize ccache usage if possible")
set_default(BATTLESHIPS_USE_CLANG 1
  CACHE STRING "Whether to prioitize clang usage if possible")
# Standard Variables

# Attempt to parallelize build
include(ProcessorCount)
ProcessorCount(CPU_CORES)
if(NOT CPU_CORES EQUAL 0)
  set(CMAKE_BUILD_PARALLEL_LEVEL ${CPU_CORES})
endif(NOT CPU_CORES EQUAL 0)

# Enable Compiler Cache if possible
if( (NOT ${CCACHE_FOUND} STREQUAL "") AND "${BATTLESHIPS_USE_CCACHE}")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  message("ccache : Detected program launcher will be used")
endif()

# Use clang compiler if possible
find_program(CLANG_FOUND "clang")
if( (NOT ${CLANG_FOUND} STREQUAL "") AND "${BATTLESHIPS_USE_CLANG}")
  set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
  message("clang : Detected compiler will be used")
endif()

# Target Properties
set_target_properties(battleships PROPERTIES
  CXX_STANDARD "${BATTLESHIPS_MINIMUM_CXX_STANDARD}"
  # Output Direcorties
  # The '$<0:>' is a cmake generator expression to prevent multi-target build
  # generators like Microsoft Visual Studio from manipulating output directories
  RUNTIME_OUTPUT_DIRECTORY ${BATTLESHIPS_BINARY_DIR}$<0:>
  LIBRARY_OUTPUT_DIRECTORY ${BATTLESHIPS_LIBRARY_DIR}$<0:>
  ARCHIVE_OUTPUT_DIRECTORY ${BATTLESHIPS_ARTIFACT_DIR}$<0:>
  COMPILE_PDB_OUTPUT_DIRECTORY ${BATTLESHIPS_DEBUG_DIR}$<0:>)
