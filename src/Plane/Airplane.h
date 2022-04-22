#ifndef CONTROLEAERIEN_GROUPE_1_B_AIRPLANE_H
#define CONTROLEAERIEN_GROUPE_1_B_AIRPLANE_H

#include <iostream>
#include <vector>
//#include "../Plane/Plane.h"

class Airplane {
private :
    std::string model, type;
    int id;
    bool state;
    double comsuption, speed, landing_speed, takeoff_speed, fuel_capacity;
public:
    Airplane(std::string &airplane_model, int &airplane_id, std::string &airplane_type, bool &airplane_state,
             double &airplane_comsuption, double &airplane_speed, double &airplane_landing_speed,
             double &airplane_takeoff_speed,
             double &airplane_fuel_capacity);

    std::string get_model() const;

    int get_id() const;

    std::string get_type() const;

    bool get_state() const;

    double get_plane_comsuption() const;

    double get_speed() const;

    double get_landing_speed() const;

    double get_takeoff_speed() const;

    double get_fuel_capacity() const;

    void put_state(bool plane_state);

    void afficher() const;

    //Airplane GetPlane(Plane plane) const;//obligation d'appler la fonction dans le main
};


#endif //CONTROLEAERIEN_GROUPE_1_B_AIRPLANE_H
