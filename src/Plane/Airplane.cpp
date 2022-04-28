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

void Airplane::set_plane_x(float plane_x) {
    x = plane_x;
}

void Airplane::set_plane_y(float plane_y) {
    y = plane_y;
}

sf::Sprite Airplane::get_Sprite() const {
    return airplane_pic;
}

void Airplane::set_Coord_plane(float plane_x, float plane_y) {
    airplane_pic.setPosition(plane_x, plane_y);
}

void Plane_Movement(sf::Event event, sf::RenderWindow &window, Plane &airplane, Aiport_network &a, sf::Sprite &Sprite) {
    //window.setFramerateLimit(80);
    float duree = 5;

    airplane.getListPlane()[1]->set_plane_x((float) a.getListAirport()[0]->getXcentre());
    airplane.getListPlane()[1]->set_plane_y((float) a.getListAirport()[0]->getYcentre());
    airplane.getListPlane()[1]->set_Coord_plane(airplane.getListPlane()[1]->get_plane_x(),
                                                airplane.getListPlane()[1]->get_plane_y());

    //float xVelocity = (float) a.getListAirport()[1]->getXcentre()/(float)duree ;//UT
    //float yVelocity = (float) a.getListAirport()[1]->getYcentre()/(float)duree;
    float progression = 0;

    sf::Time dt;


    while (window.isOpen()) {
        sf::Clock clock;
        float count = dt.asSeconds();
        if (progression < duree) {
            progression += count;
            //xVelocity *= -1;
        } else {
            progression = duree;
        }

        airplane.getListPlane()[1]->set_plane_x((float) airplane.getListPlane()[1]->get_plane_x() +
                                                linear(progression, (float) a.getListAirport()[0]->getXcentre(),
                                                       (float) a.getListAirport()[1]->getXcentre() -
                                                       (float) a.getListAirport()[0]->getXcentre(),
                                                       duree));
        airplane.getListPlane()[1]->set_plane_y((float) airplane.getListPlane()[1]->get_plane_y() +
                                                linear(progression, (float) a.getListAirport()[0]->getYcentre(),
                                                       (float) a.getListAirport()[1]->getYcentre() -
                                                       (float) a.getListAirport()[0]->getYcentre(),
                                                       duree));

        airplane.getListPlane()[1]->set_Coord_plane(airplane.getListPlane()[1]->get_plane_x(),
                                                    airplane.getListPlane()[1]->get_plane_y());
        if (airplane.getListPlane()[1]->get_plane_x() == (float) a.getListAirport()[1]->getXcentre() &&
            airplane.getListPlane()[1]->get_plane_y() == (float) a.getListAirport()[1]->getYcentre()) {
            std::cout << "Arivée";
            window.clear();
            window.draw(Sprite);
        } else {
            window.clear();
            window.draw(Sprite);
            window.draw(airplane.getListPlane()[1]->get_Sprite());
        }
        dt= clock.getElapsedTime();
        clock.restart();
        window.display();
    }


}


float linear(float passed_time, float start_value, float Long, float total_time) {
    return (Long * passed_time) / (start_value + total_time);
}



/*Airplane Airplane::GetPlane(Plane plane) const {
    return Airplane(__cxx11::basic_string(), <#initializer#>, __cxx11::basic_string(), <#initializer#>, <#initializer#>,
                    <#initializer#>, <#initializer#>, <#initializer#>, <#initializer#>);
}*/
