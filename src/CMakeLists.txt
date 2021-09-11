cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(proj_name daoshu)

# set(CMAKE_CXX_FLAGS "-g") 
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE MinSizeRel)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


configure_file(daoshu.desktop dist/daoshu.desktop copyonly)
configure_file(daoshu.svg dist/daoshu.svg copyonly)
configure_file(daoshu_small.svg dist/daoshu_small.svg copyonly)

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
PKG_CHECK_MODULES(LIBNOTIFY libnotify>=0.7.6) 
message(libnotify_inc ": ${libnotify_include_dirs}")
message(libnotify_libs ": ${libnotify_libraries}")

include(LibFindMacros)

libfind_pkg_check_modules(libpulse_PKGCONF libpulse)
find_path(libpulse_INCLUDE_DIR
  NAMES pulse/error.h
  HINTS ${libpulse_PKGCONF_INCLUDE_DIRS}
)
find_library(libpulse_LIBRARY
  NAMES pulse
  HINTS ${libpulse_PKGCONF_LIBRARY_DIRS}
)

libfind_pkg_check_modules(libpulsesimple_PKGCONF libpulse-simple)
find_path(libpulsesimple_INCLUDE_DIR
  NAMES pulse/simple.h
  HINTS ${libpulsesimple_PKGCONF_INCLUDE_DIRS}
)
find_library(libpulsesimple_LIBRARY
  NAMES pulse-simple
  HINTS ${libpulsesimple_PKGCONF_LIBRARY_DIRS}
)

message(libpulse_inc ":${libpulse_INCLUDE_DIR}")
message(libpulse_libs ": ${libpulse_LIBRARY}")
message(libpulse_simple_inc ":${libpulsesimple_INCLUDE_DIR}")
message(libpulse_simple_libs ": ${libpulsesimple_LIBRARY}")

pkg_search_module(glib REQUIRED glib-2.0)
message(glib_inc ": ${glib_INCLUDE_DIRS}")
message(glib_libs ": ${glib_LDFLAGS}")


# include(cotire)

add_executable(${proj_name} daoshu/${proj_name}.cpp  ${proj_name}/arc_progress.cpp 
    ${proj_name}/controls.cpp  
    ${proj_name}/daoshu_window.cpp  
    ${proj_name}/daoshu_notify.cpp  
    ${proj_name}/play_sound.cpp  
    ${proj_name}/bell.o  
    )
message(CONAN_LIBS ": ${CONAN_LIBS}")

target_include_directories(${proj_name} PRIVATE 
  ${glib_INCLUDE_DIRS}  
  ${LIBNOTIFY_INCLUDE_DIRS} 
  ${libpulsesimple_PKGCONF_INCLUDE_DIRS}    
  )
target_link_libraries(${proj_name} 
  ${CONAN_LIBS} 
  Qt5::Core
  Qt5::Widgets
  ${libpulse_LIBRARY} 
  ${libpulsesimple_LIBRARY} 
  ${LIBNOTIFY_LIBRARIES} 
  ${glib_LDFLAGS}
  )


# cotire(${proj_name})