cmake_minimum_required(VERSION 3.17)
project(ProjetGit)

    set(CMAKE_CXX_STANDARD 14)

    add_executable(ProjetGit main.cpp src/Menu/Menu.cpp src/Menu/Menu.h src/Airport/Airport.cpp src/Airport/Airport.h src/Plane/Plane.cpp src/Plane/Plane.h src/Airport_network/Aiport_network.cpp src/Airport_network/Aiport_network.h src/Case/Case.cpp src/Case/Case.h src/Flight/Flight.cpp src/Flight/Flight.h src/Flying_time/Flying_time.cpp src/Flying_time/Flying_time.h)
    set  (SFML_STATIC_LIBRARIES TRUE)
    set  (SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package ( SFML COMPONENTS system window graphics audio network REQUIRED)

    include_directories (C:/SFML/include)
    target_link_libraries(ProjetGit sfml-system sfml-window sfml-graphics sfml-audio sfml-network )
