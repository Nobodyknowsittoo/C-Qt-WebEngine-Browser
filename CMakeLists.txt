cmake_minimum_required(VERSION 3.16)

project(QtWebEngineBrowser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets WebEngineWidgets)

add_executable(QtWebEngineBrowser main.cpp)

target_link_libraries(QtWebEngineBrowser
    PRIVATE Qt6::Widgets Qt6::WebEngineWidgets
)
