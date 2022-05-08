#ifndef CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#define CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
#include "../Plane/Plane.h"
#include "../Airport_network/Aiport_network.h"
#include "../Menu/Menu.h"

class Airport;
class Airplane;
class Plane;
class Aiport_network;

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

    std::vector<Airport *> get_list_airport() const;

    std::vector<Airplane *> get_list_plane() const;

    void Flight_manual();

    void set_departure();

    void set_arrival();

    void afficher() const;

    void set_list_plane(std::vector<Airplane *> plane);

    void set_list_airport(std::vector<Airport *> Airport);

    std::vector<int> PCC ();
};
void init_flight(std::vector<Flight *> &ALl_flight, size_t i, int &num_departure_airport, int &num_arrival_airport,
                 sf::Vector2f &(Airport1), sf::Vector2f &(Airport2),std::vector<std::vector<int>> &flight_plan,  int &j, bool &ok);

void Plane_Movement(sf::RenderWindow &window, sf::Sprite &Sprite, bool &enter_manual, std::vector<Flight *> &ALl_flight, Plane p, Aiport_network a);

sf::Vector2f (Interpolate(const sf::Vector2f (&pointA), const sf::Vector2f (&pointB), float factor));

double angle(float airport1X, float airport1Y,float airport2X, float airport2Y );

float module(float x, float y);
#endif //CONTROLEAERIEN_GROUPE_1_B_FLIGHT_H
