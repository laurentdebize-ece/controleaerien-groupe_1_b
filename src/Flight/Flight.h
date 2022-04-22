#ifndef CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#define CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#include "../Plane/Plane.h"
#include "../Airport_network/Aiport_network.h"

class Flight {
private:
    std::string flight_id, departure, arrival;
    //Airplane* airplane_flight;
    std::vector<Airplane *> m_list_of_plane;
    //Airport* m_airport;
    std::vector<Airport *> m_list_of_airport;
    //vector of Airport
public:
    Flight(std::vector<Airplane *> list_of_plane,std::vector<Airport *> list_of_airport);
    ~Flight();
    std::string get_flight_id() const;
    std::string get_departure() const;
    std::string get_arrival() const;
    void Flight_manual();
    void put_departure();
    void put_arrival();
    void afficher() const;
};


#endif //CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
