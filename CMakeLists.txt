cmake_minimum_required(VERSION 3.17)
project(ProjetGit)

    set(CMAKE_CXX_STANDARD 14)

    add_executable(ProjetGit main.cpp main.cpp)
    set  (SFML_STATIC_LIBRARIES TRUE)
    set  (SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package ( SFML COMPONENTS system window graphics audio network REQUIRED)

    include_directories (C:/SFML/include)
    target_link_libraries(ProjetGit sfml-system sfml-window sfml-graphics sfml-audio sfml-network )
