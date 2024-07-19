cmake_minimum_required(VERSION 3.26)
project(qt-qrc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

if (MSVC)
    add_compile_options("/utf-8")
endif ()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "build type" FORCE)
endif ()
message(STATUS ${CMAKE_BUILD_TYPE})

# set
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(fmt REQUIRED)


add_executable(qrc main.cpp
        qrc_dialog.cpp
        qrc_dialog.h
)
target_link_libraries(qrc
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        fmt::fmt-header-only
)

