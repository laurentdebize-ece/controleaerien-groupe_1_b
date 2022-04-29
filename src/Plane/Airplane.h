#ifndef CONTROLEAERIEN_GROUPE_1_B_AIRPLANE_H
#define CONTROLEAERIEN_GROUPE_1_B_AIRPLANE_H

#include <iostream>
#include <vector>
//#include "../Plane/Plane.h"
#include <SFML/Graphics.hpp>
#include "../Airport/Airport.h"
#include <cmath>

class Airport;
class Plane;
class Aiport_network;

class Airplane {
private :
    std::string model, type;
    int id;
    bool takeoff;
    bool state;
    double comsuption, speed, landing_speed, takeoff_speed, fuel_capacity;
    float x,y;
    sf::Sprite airplane_pic;
public:
    Airplane(std::string &airplane_model, int &airplane_id, std::string &airplane_type, bool &airplane_state,
             double &airplane_comsuption, double &airplane_speed, double &airplane_landing_speed,
             double &airplane_takeoff_speed,
             double &airplane_fuel_capacity, sf::Sprite &pic);

    std::string get_model() const;

    int get_id() const;

    std::string get_type() const;

    bool get_state() const;

    bool get_if_takeoff() const;

    double get_plane_comsuption() const;

    double get_speed() const;

    double get_landing_speed() const;

    double get_takeoff_speed() const;

    double get_fuel_capacity() const;

    float get_plane_x() const;

    float get_plane_y() const;

    sf::Sprite get_Sprite() const;

    void put_state(bool plane_state);

    void takeoff_or_not(bool if_takeoff);

    void set_plane_x( float plane);

    void set_plane_y(float plane);

    void set_Coord_plane(float plane_x, float plane_y);

    void set_Angle(float angle);

    void afficher() const;


    //Airplane GetPlane(Plane plane) const;//obligation d'appler la fonction dans le main
};


void Plane_Movement(sf::Event event, sf::RenderWindow &window,  Plane &airplane, Aiport_network &a, sf::Sprite &Sprite);
sf::Vector2f (Interpolate(const sf::Vector2f (&pointA), const sf::Vector2f (&pointB), float factor));
float angle(float airport1X, float airport1Y,float airport2X, float airport2Y );
#endif //CONTROLEAERIEN_GROUPE_1_B_AIRPLANE_H
