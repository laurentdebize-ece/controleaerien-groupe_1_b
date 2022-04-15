#include "Plane.h"
#include <fstream>
#include <queue>
#include <sstream>

Plane::Plane(std::string cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    std::string ligne;
    while (std::getline(ifs, ligne)) {
        std::stringstream ss;
        size_t posit = ligne.find(" ");
        std::string airplane_id = ligne.substr(0, posit);
        ss << ligne.substr(posit);
        std::string airplane_type;
        bool nstate;
        double ncomsuption, nspeed, nlanding_speed, ntakeoff_speed, nfuel_capacity;
        ss >> airplane_type >> nstate >> ncomsuption >> nspeed >> nlanding_speed >> ntakeoff_speed >> nfuel_capacity;
        id.push_back(airplane_id);
        type.push_back(airplane_type);
        state.push_back(nstate);
        comsuption.push_back(ncomsuption);
        speed.push_back(nspeed);
        landing_speed.push_back(nlanding_speed);
        takeoff_speed.push_back(ntakeoff_speed);
        fuel_capacity.push_back(nfuel_capacity);
    }
}

Plane::~Plane() = default;

std::vector<std::string> Plane::get_id() const {
    return id;
}

std::vector<std::string> Plane::get_type() const {
    return type;
}

std::vector<bool> Plane::get_state() const {
    return state;
}

std::vector<double> Plane::get_plane_comsuption() const {
    return comsuption;
}

std::vector<double> Plane::get_speed() const {
    return speed;
}

std::vector<double> Plane::get_landing_speed() const {
    return landing_speed;
}

std::vector<double> Plane::get_takeoff_speed() const {
    return takeoff_speed;
}

std::vector<double> Plane::get_fuel_capacity() const {
    return fuel_capacity;
}

void Plane::afficher() const {
    for (int i = 0; i < 20; ++i) {
        std::cout << "*";
    }
    std::cout << " AIRPLANE INFORMATION ";
    for (int i = 0; i < 25; ++i) {
        std::cout << "*";
    }
    std::cout << "\n";
    for (size_t i(0); i < id.size(); i++) {
        std::cout << "                   Id : " << id[i] << std::endl;
        std::cout << "                   Type : " << type[i] << std::endl;
        if (!state[i]) {
            std::cout << "                   State : Off flight " << std::endl;
        } else {
            std::cout << "                   State : On flight " << std::endl;
        }
        std::cout << "                   Speed : " << speed[i] << std::endl;
        std::cout << "                   Landing Speed : " << landing_speed[i] << std::endl;
        std::cout << "                   Take off Speed : " << takeoff_speed[i] << std::endl;
        std::cout << "                   Fuel Capacity : " << speed[i] << "\n" << std::endl;
    }
    for (int j = 0; j < 67; ++j) {
        std::cout << "*";
    }
    std::cout << "\n";
}














