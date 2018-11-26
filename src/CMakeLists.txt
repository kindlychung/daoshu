
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(proj_name daoshu)
set(CMAKE_CXX_FLAGS "-g") 

set(CMAKE_POSITION_INDEpENDENT_CODE ON)
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


project(${proj_name} CXX)
set(conan_cmake_file "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
if(EXISTS ${conan_cmake_file})
    include(${conan_cmake_file})
    conan_basic_setup()
endif()
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
endif ()

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(LIBNOTIFY required libnotify>=0.7.6) 
PKG_CHECK_MODULES(LIBPULSE required libpulse>=12.0) 
INCLUDE_DIRECTORIES(${LIBNOTIFY_INCLUDE_DIRS})
LINK_DIRECTORIES(${LIBNOTIFY_LIBRARY_DIRS})

include(LibFindMacros)
libfind_pkg_check_modules(LibPulse_PKGCONF libpulse)
find_path(LibPulse_INCLUDE_DIR
  NAMES pulse/error.h
  HINTS ${LibPulse_PKGCONF_INCLUDE_DIRS}
)
find_library(LibPulse_LIBRARY
  NAMES pulse
  HINTS ${LibPulse_PKGCONF_LIBRARY_DIRS}
)
libfind_pkg_check_modules(LibPulseSimple_PKGCONF libpulse-simple)
find_path(LibPulseSimple_INCLUDE_DIR
  NAMES pulse/simple.h
  HINTS ${LibPulseSimple_PKGCONF_INCLUDE_DIRS}
)
find_library(LibPulseSimple_LIBRARY
  NAMES pulse-simple
  HINTS ${LibPulseSimple_PKGCONF_LIBRARY_DIRS}
)
INCLUDE_DIRECTORIES(${LibPulseSimple_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${LibPulse_INCLUDE_DIR})
message(pulse_simple_libs ": ${LibPulseSimple_LIBRARY}")
message(pulse_libs ": ${LibPulse_LIBRARY}")

# include(cotire)

add_executable(${proj_name} daoshu/${proj_name}.cpp  ${proj_name}/arc_progress.cpp 
    ${proj_name}/controls.cpp  
    ${proj_name}/daoshu_window.cpp  
    ${proj_name}/daoshu_notify.cpp  
    ${proj_name}/play_sound.cpp  
    ${proj_name}/bell.o  
    )
message(CONAN_LIBS ": ${CONAN_LIBS}")
# target_link_libraries(${proj_name} ${CONAN_LIBS} Qt5::Core Qt5::Widgets -lpulse -lpulse-simple ${LIBNOTIFY_LIBRARIES})
target_link_libraries(${proj_name} ${CONAN_LIBS} Qt5::Core Qt5::Widgets ${LibPulse_LIBRARY} ${LibPulseSimple_LIBRARY} ${LIBNOTIFY_LIBRARIES})

# cotire(${proj_name})
