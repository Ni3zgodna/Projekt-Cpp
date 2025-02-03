cmake_minimum_required(VERSION 3.5)
project(Projekt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

add_executable(Projekt
    main.cpp
    matematyka.cpp
    matematyka.h
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    Resources.qrc

)

include(GNUInstallDirs)

install(TARGETS Projekt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(Projekt PRIVATE
    Qt6::Widgets
    Qt6::Multimedia
)


set_target_properties(Projekt PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
)
