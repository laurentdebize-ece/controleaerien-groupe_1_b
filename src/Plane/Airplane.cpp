#include "Airplane.h"

Airplane::Airplane(std::string &airplane_model, int &airplane_id, std::string &airplane_type, bool &airplane_state,
                   double &airplane_comsuption,
                   double &airplane_speed, double &airplane_landing_speed, double &airplane_takeoff_speed,
                   double &airplane_fuel_capacity, sf::Sprite &pic) :
        model{airplane_model}, id{airplane_id}, type{airplane_type}, state{airplane_state},
        comsuption{airplane_comsuption},
        speed{airplane_speed}, landing_speed{airplane_landing_speed}, takeoff_speed{airplane_takeoff_speed},
        fuel_capacity{airplane_fuel_capacity}, takeoff{false}, x{0}, y{0}, airplane_pic{pic} {

}

std::string Airplane::get_model() const {
    return model;
}

int Airplane::get_id() const {
    return id;
}

std::string Airplane::get_type() const {
    return type;
}

bool Airplane::get_state() const {
    return state;
}

bool Airplane::get_if_takeoff() const {
    return takeoff;
}

double Airplane::get_plane_comsuption() const {
    return comsuption;
}

double Airplane::get_speed() const {
    return speed;
}

double Airplane::get_landing_speed() const {
    return landing_speed;
}

double Airplane::get_takeoff_speed() const {
    return takeoff_speed;
}

double Airplane::get_fuel_capacity() const {
    return fuel_capacity;
}

void Airplane::afficher() const {
    std::cout << "                   Model : " << model << std::endl
              << "                   Id : " << id << std::endl
              << "                   Type : " << type << std::endl;
    if (!state) {
        std::cout << "                   State : Off flight " << std::endl;
    } else {
        std::cout << "                   State : On flight " << std::endl;
    }
    std::cout << "                   Speed : " << speed << std::endl
              << "                   Landing Speed : " << landing_speed << std::endl
              << "                   Take off Speed : " << takeoff_speed << std::endl
              << "                   Fuel Capacity : " << speed << "\n" << std::endl;
}

void Airplane::put_state(bool plane_state) {
    state = plane_state;
}

void Airplane::takeoff_or_not(bool if_takeoff) {
    takeoff = if_takeoff;
}

float Airplane::get_plane_x() const {
    return x;
}

float Airplane::get_plane_y() const {
    return y;
}

void Airplane::set_plane_x(float plane) {
    x = plane;
}

void Airplane::set_plane_y(float plane) {
    y = plane;
}

sf::Sprite Airplane::get_Sprite() const {
    return airplane_pic;
}

void Airplane::set_Coord_plane(float plane_x, float plane_y) {
    airplane_pic.setPosition(plane_x, plane_y);
}


void Plane_Movement(sf::Event event, sf::RenderWindow &window, Plane &airplane, Aiport_network &a, sf::Sprite &Sprite) {
    window.setFramerateLimit(60);
    int num_arrival_airport=5, num_departure_airport=0, num_airplane=10;
    bool fin(false);

    float vitesse = 0.05f;
    sf::Vector2f (Airport1), (Airport2), (vec);

    airplane.getListPlane()[num_airplane]->set_plane_x( (float)a.getListAirport()[num_departure_airport]->getXcentre());
    airplane.getListPlane()[num_airplane]->set_plane_y((float)a.getListAirport()[num_departure_airport]->getYcentre());
    airplane.getListPlane()[num_airplane]->set_Coord_plane(airplane.getListPlane()[num_airplane]->get_plane_x(),
                                                airplane.getListPlane()[num_airplane]->get_plane_y());

    Airport1.x=(float)a.getListAirport()[num_departure_airport]->getXcentre();
    Airport1.y=(float)a.getListAirport()[num_departure_airport]->getYcentre();

    Airport2.x=(float)a.getListAirport()[num_arrival_airport]->getXcentre();
    Airport2.y=(float)a.getListAirport()[num_arrival_airport]->getYcentre();

    float progression = 0.f;

    sf::Clock clock;
    do{
        progression += clock.getElapsedTime().asSeconds()*vitesse;
        clock.restart();

        airplane.getListPlane()[num_airplane]->set_plane_x(Interpolate(Airport1,Airport2,progression).x);
        airplane.getListPlane()[num_airplane]->set_plane_y(Interpolate(Airport1,Airport2,progression).y);

        airplane.getListPlane()[num_airplane]->set_Coord_plane(airplane.getListPlane()[num_airplane]->get_plane_x(),
                                                    airplane.getListPlane()[num_airplane]->get_plane_y());
        if ((airplane.getListPlane()[num_airplane]->get_plane_x() == (float) a.getListAirport()[num_airplane]->getXcentre() &&
            airplane.getListPlane()[num_airplane]->get_plane_y() == (float) a.getListAirport()[num_airplane]->getYcentre())||progression>1) {
            std::cout << "Arivée";
            window.clear();
            window.draw(Sprite);
            fin=true;
        } else {
            window.clear();
            window.draw(Sprite);
            window.draw(airplane.getListPlane()[num_airplane]->get_Sprite());
            fin=false;
        }

        window.display();

    } while (!fin);
}

sf::Vector2f (Interpolate(const sf::Vector2f (&pointA), const sf::Vector2f (&pointB), float factor))  {
    if(factor > 1.f) {
        factor = 1.f;
    }
    else if(factor < 0.f) {
        factor = 0.f;
    }
    return pointA + (pointB - pointA) * factor;
}



/*Airplane Airplane::GetPlane(Plane plane) const {
    return Airplane(__cxx11::basic_string(), <#initializer#>, __cxx11::basic_string(), <#initializer#>, <#initializer#>,
                    <#initializer#>, <#initializer#>, <#initializer#>, <#initializer#>);
}*/
