//
// Created by Jojo on 4/13/22.
//

#ifndef CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#define CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#include "../Plane/Plane.h"

class Flight {
private:
    std::string flight_id, departure, arrival;
    Airplane* airplane_flight;
    std::vector<Airplane *> list_of_plane;
    //vector of Airport
public:
    Flight();
    ~Flight();
    void Flight_manual();
    std::string get_flight_id() const;
    std::string get_departure() const;
    std::string get_arrival() const;
    void put_departure();
    void put_arrival();
    void afficher() const;
};


#endif //CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
