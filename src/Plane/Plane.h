#ifndef CONTROLEAERIEN_GROUPE_1_B_PLANE_H
#define CONTROLEAERIEN_GROUPE_1_B_PLANE_H
#include <iostream>
#include <vector>

class Plane {
private:
    std::vector<std::string> id, type;
    std::vector<bool> state;
    std::vector<double> comsuption, speed, landing_speed,takeoff_speed, fuel_capacity;
public:
    Plane(std::string cheminFichierGraphe);
    ~Plane();
    std::vector<std::string> get_id() const;
    std::vector<std::string> get_type() const;
    std::vector<bool> get_state() const;
    std::vector<double> get_plane_comsuption() const;
    std::vector<double> get_speed() const;
    std::vector<double> get_landing_speed() const;
    std::vector<double> get_takeoff_speed() const;
    std::vector<double> get_fuel_capacity() const;
    void afficher() const;
};


#endif //CONTROLEAERIEN_GROUPE_1_B_PLANE_H
