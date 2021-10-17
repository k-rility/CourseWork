cmake_minimum_required(VERSION 3.15)
project(course_work)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

if (ANDROID)
    add_library(course_work SHARED
            demo/main.cpp
            sources/auth_window.cpp
            include/auth_window.hpp
            ui/auth_window.ui

            sources/data_base.cpp
            include/data_base.hpp

            include/main_window.hpp
            sources/main_window.cpp
            ui/main_window.ui

            include/reg_customers_window.hpp
            sources/reg_customers_window.cpp
            ui/reg_customers_window.ui
            )
else ()
    add_executable(course_work
            demo/main.cpp
            sources/auth_window.cpp
            include/auth_window.hpp
            ui/auth_window.ui

            sources/data_base.cpp
            include/data_base.hpp

            include/main_window.hpp
            sources/main_window.cpp
            ui/main_window.ui

            include/reg_customers_window.hpp
            sources/reg_customers_window.cpp
            ui/reg_customers_window.ui
            )
endif ()

target_link_libraries(course_work Qt5::Widgets Qt5::Core Qt5::Sql)
