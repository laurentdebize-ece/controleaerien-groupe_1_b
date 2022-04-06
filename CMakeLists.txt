cmake_minimum_required(VERSION 3.17)
project(controleaerien-groupe_1_b)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.cpp)
add_executable(controleaerien-groupe_1_b ${SOURCE_FILES} main.cpp)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(controleaerien-groupe_1_b sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


IF(WIN32)
    set(CMAKE_CXX_STANDARD 14)

    add_executable(controleaerien-groupe_1_b main.cpp main.cpp)
    set  (SFML_STATIC_LIBRARIES TRUE)
    set  (SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package ( SFML COMPONENTS system window graphics audio network REQUIRED)

    include_directories (C:/SFML/include)
    target_link_libraries(controleaerien-groupe_1_b  sfml-system sfml-window sfml-graphics sfml-audio sfml-network )
ENDIF(WIN32)