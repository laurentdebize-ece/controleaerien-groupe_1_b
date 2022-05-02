#ifndef CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#define CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#include "../Plane/Plane.h"
#include "../Airport_network/Aiport_network.h"
#include "../Menu/Menu.h"

class Airport;
class Airplane;

class Flight {
private:
    std::string flight_id, departure, arrival;
    int id_plane;
    std::vector<Airplane *> m_list_of_plane;
    std::vector<Airport *> m_list_of_airport;
public:
    Flight(std::vector<Airplane *> list_of_plane,std::vector<Airport *> list_of_airport, bool &enter_manual);

    ~Flight();

    std::string get_flight_id() const;

    int get_departure_num() const;

    int get_arrival_num() const;

    Airport* get_departure() const;

    Airport* get_arrival() const;

    Airplane* get_airplane() const;

    void Flight_manual();

    void put_departure();

    void put_arrival();

    void afficher() const;

    void Plane_Movement(sf::RenderWindow &window, sf::Sprite &Sprite, bool &enter_manual);

    std::vector<int> PCC ();
};

sf::Vector2f (Interpolate(const sf::Vector2f (&pointA), const sf::Vector2f (&pointB), float factor));
double angle(float airport1X, float airport1Y,float airport2X, float airport2Y );
float module(float x, float y);
#endif //CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
