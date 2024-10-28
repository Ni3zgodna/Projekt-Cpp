cmake_minimum_required(VERSION 3.5)
project(Projekt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Projekt main.cpp
    funkcje.cpp
    projekt.h
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
)

include(GNUInstallDirs)

install(TARGETS Projekt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(Projekt PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(Projekt PRIVATE Qt6::Widgets)
