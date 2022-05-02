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

void Airplane::set_Angle(float angle){
        airplane_pic.setRotation(angle);
}

void Airplane::set_Coord_plane(float plane_x, float plane_y) {
    airplane_pic.setPosition(plane_x, plane_y);
}


void Plane_Movement(sf::Event event, sf::RenderWindow &window, Plane &airplane, Aiport_network &a, sf::Sprite &Sprite) {
    //TURBULENCE
    sf::Texture animTexture;
    if (!animTexture.loadFromFile("Graphic_Content/turbulence/Rain_animation.png")) {
        std::cout << "bullshit";
    }
    sf::Vector2i spriteSize(30, 30);
    std::vector<sf::Sprite> animSprites;//vecteur de sprite

    int sheetRow = (int)animTexture.getSize().y / spriteSize.y;
    int sheetColumn = (int)animTexture.getSize().x / spriteSize.x;

    for (int i = 0; i < sheetRow; i++) {
        for (int j = 0; j < sheetColumn; j++) {
            animSprites.emplace_back(animTexture, sf::IntRect(spriteSize.x * j, spriteSize.y * i, spriteSize.x, spriteSize.y));
        }
    }

    for (int i = sheetRow - 1; i >= 0; i--) {
        for (int j = sheetColumn - 1; j >= 0; j--) {
            animSprites.emplace_back(animTexture, sf::IntRect(spriteSize.x * j, spriteSize.y * i, spriteSize.x, spriteSize.y));
        }
    }

    for (int i = 0; i < animSprites.size(); i++) {
        sf::FloatRect animSpriteRect = animSprites[i].getLocalBounds();
        animSprites[i].setOrigin(animSpriteRect.width / 2.0f, animSpriteRect.height / 2.0f);
        animSprites[i].setPosition((float)window.getSize().x / 2.0f, (float)window.getSize().y / 2.0f);
    }

    int frameIndex = 0;
    float frameDuration = 0.4f; // Each frame takes aruond 1/10 sec.







    window.setFramerateLimit(60);
    int num_arrival_airport = 3, num_departure_airport = 8, num_airplane = 1;
    bool fin(false);

    float vitesse = 0.19f;
    sf::Vector2f (Airport1), (Airport2);

    airplane.getListPlane()[num_airplane]->set_plane_x((float) a.getListAirport()[num_departure_airport]->getXcentre());
    airplane.getListPlane()[num_airplane]->set_plane_y((float) a.getListAirport()[num_departure_airport]->getYcentre());
    airplane.getListPlane()[num_airplane]->set_Coord_plane(airplane.getListPlane()[num_airplane]->get_plane_x(),
                                                           airplane.getListPlane()[num_airplane]->get_plane_y());

    Airport1.x = (float) a.getListAirport()[num_departure_airport]->getXcentre();
    Airport1.y = (float) a.getListAirport()[num_departure_airport]->getYcentre();

    Airport2.x = (float) a.getListAirport()[num_arrival_airport]->getXcentre();
    Airport2.y = (float) a.getListAirport()[num_arrival_airport]->getYcentre();

    float progression = 0.f;

    sf::Clock clock;
    do {
        progression += clock.getElapsedTime().asSeconds() * vitesse;
        clock.restart();

        airplane.getListPlane()[num_airplane]->set_plane_x(Interpolate(Airport1, Airport2, progression).x);
        airplane.getListPlane()[num_airplane]->set_plane_y(Interpolate(Airport1, Airport2, progression).y);

        airplane.getListPlane()[num_airplane]->set_Coord_plane(airplane.getListPlane()[num_airplane]->get_plane_x(),
                                                               airplane.getListPlane()[num_airplane]->get_plane_y());
        if ((airplane.getListPlane()[num_airplane]->get_plane_x() ==
             (float) a.getListAirport()[num_arrival_airport]->getXcentre() &&
             airplane.getListPlane()[num_airplane]->get_plane_y() ==
             (float) a.getListAirport()[num_arrival_airport]->getYcentre()) || progression > 1) {
            std::cout << "Arrive";
            window.clear();
            window.draw(Sprite);

            fin = true;
        } else {
            window.clear(sf::Color(0, 0, 0));
            window.draw(Sprite);



            if(a.getListAirport()[num_departure_airport]->getXcentre()>a.getListAirport()[num_arrival_airport]->getXcentre()) {
                airplane.getListPlane()[num_airplane]->set_Angle( (float) angle(Airport1.x, Airport1.y, Airport2.x, Airport2.x)+180.0f);
            }
            else {
                airplane.getListPlane()[num_airplane]->set_Angle(
                        (float) angle(Airport1.x, Airport1.y, Airport2.x, Airport2.x)+150.f);
            }
            window.draw(airplane.getListPlane()[num_airplane]->get_Sprite());
            /*if (clock.getElapsedTime().asSeconds() >= frameDuration) {
                frameIndex++;
                frameIndex = frameIndex % (int)(animSprites.size());

                clock.restart();
            }

            window.clear(sf::Color(0, 0, 0));
            window.draw(animSprites[frameIndex]);
            window.display();*/
            fin = false;
        }


       /*while (window.isOpen()) {
           // sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            if (clock.getElapsedTime().asSeconds() >= frameDuration) {
                frameIndex++;
                frameIndex = frameIndex % (int)(animSprites.size());

                clock.restart();
            }

            window.clear(sf::Color(0, 0, 0));
            window.draw(animSprites[frameIndex]);
            window.display();
        }*/

        window.display();

    } while (!fin);

    /*std::cout <<" nuage";
    window.draw(viewmeteo);
    window.display();*/
    /*while (window.isOpen()) {
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::L) {
                std::cout << " nuage";
                window.clear();
                window.draw(viewmeteo);
                //a.show_network_airport_line_on_screen(event, window, Sprite, font);
                window.display();
            }
            if (event.key.code == sf::Keyboard::J) {
                std::cout << " nuagedead";
                window.clear();
                window.draw(viewmeteo);
                window.display();
            }
        }
    }*/
}

sf::Vector2f (Interpolate(const sf::Vector2f (&pointA), const sf::Vector2f (&pointB), float factor)) {
    if (factor > 1.f) {
        factor = 1.f;
    } else if (factor < 0.f) {
        factor = 0.f;
    }
    return pointA + (pointB - pointA) * factor;
}

double angle(float airport1X, float airport1Y, float airport2X, float airport2Y) {

    float oposite_long = module(airport2X - airport1X, airport2Y - airport2Y);
    float hypo = module(airport2X - airport1X, airport2Y - airport1Y);

    return asin(oposite_long / hypo) * 180.0 / PI;
}

float module(float x, float y) {
    return sqrt(x * x + y * y);
}

/*Airplane Airplane::GetPlane(Plane plane) const {
    return Airplane(__cxx11::basic_string(), <#initializer#>, __cxx11::basic_string(), <#initializer#>, <#initializer#>,
                    <#initializer#>, <#initializer#>, <#initializer#>, <#initializer#>);
}*/
