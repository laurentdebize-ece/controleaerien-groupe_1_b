#include "Airplane.h"

Airplane::Airplane(std::string &airplane_model, int &airplane_id, std::string &airplane_type, bool &airplane_state,
                   double &airplane_comsuption,
                   double &airplane_speed, double &airplane_landing_speed, double &airplane_takeoff_speed,
                   double &airplane_fuel_capacity) :
        model{airplane_model}, id{airplane_id}, type{airplane_type}, state{airplane_state}, comsuption{airplane_comsuption},
        speed{airplane_speed}, landing_speed{airplane_landing_speed}, takeoff_speed{airplane_takeoff_speed},
        fuel_capacity{airplane_fuel_capacity}, takeoff{false}, x{0}, y{0} {

    if(airplane_type=="ATR72-600"){
        airplane_pic.loadFromFile("Graphic_Content/Planes/ATR.png");
    }
    else if(airplane_type=="BOEING-777"){
        airplane_pic.loadFromFile("Graphic_Content/Planes/Boeing.png");
    }
    else if(airplane_type=="AIRBUS-A380"){
        airplane_pic.loadFromFile("Graphic_Content/Planes/Airbus.png");
    }
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

sf::Texture Airplane::get_texture() const{
    return airplane_pic;
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
    state=plane_state;
}

void Airplane::takeoff_or_not(bool if_takeoff) {
    takeoff=if_takeoff;
}

float Airplane::get_plane_x() const {
    return x;
}

float Airplane::get_plane_y() const {
    return y;
}

void Airplane::put_plane_x(float plane_x) {
    x=plane_x;
}

void Airplane::put_plane_y(float plane_y) {
    y=plane_y;
}

void Plane_Movement(sf::Event event, sf::RenderWindow &window, Airplane* airplane, std::vector<Airport *> &list_of_airport){
    float time=15.0f;
    float progression;
    sf::Sprite Sprite_airplane(airplane->get_texture());

    // Delta time stuff
    sf::Clock dtClock;

        // Framerate cap
        while (dtClock.getElapsedTime().asSeconds() < 1.f/50.f);

        // Calculate dt
        float dt = dtClock.restart().asSeconds();

    if(progression<time){
        progression=progression+dt;
    }
    else{
        progression=time;
    }
    airplane->put_plane_x(linear(progression,(float)list_of_airport[1]->getXcentre(),(float)list_of_airport[3]->getXcentre(),time));
    airplane->put_plane_y(linear(progression,(float)list_of_airport[1]->getYcentre(),(float)list_of_airport[3]->getYcentre(),time));
        // Non smoothed
        //player.setPosition(curState);
        window.draw(Sprite_airplane);
        window.display();
}

float linear (float passed_time, float start_value,float Long,float total_time){
    return Long*passed_time/ start_value+total_time ;
}



/*Airplane Airplane::GetPlane(Plane plane) const {
    return Airplane(__cxx11::basic_string(), <#initializer#>, __cxx11::basic_string(), <#initializer#>, <#initializer#>,
                    <#initializer#>, <#initializer#>, <#initializer#>, <#initializer#>);
}*/
