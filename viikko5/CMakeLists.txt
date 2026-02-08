cmake_minimum_required(VERSION 3.16)

project(viikko5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikko5 main.cpp
    notifikaattori.h notifikaattori.cpp
    seuraaja.h seuraaja.cpp)

include(GNUInstallDirs)
install(TARGETS viikko5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
