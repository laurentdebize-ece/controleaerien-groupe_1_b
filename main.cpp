#include "src/Menu/Menu.h"

int main() {
    unsigned int choix(0);
    bool fin(false), back_menu(true), end_flight(false), enter_manual(false);

    sf::Font font;
    font.loadFromFile("../Font/Pixeled.ttf");
    //Initialisation Cartes Map
    sf::Texture Menu_principal;

    Menu_principal.loadFromFile("../Graphic_Content/Map/Sim_Map.png");

    sf::Sprite Sprite(Menu_principal);

    sf::Vector2f targetSize(LARGEUR_FENETRE, HAUTEUR_FENETRE);

    Plane p{"../Text_files/Airplane"};
    Aiport_network a{"../Text_files/Airport_network"};

    do {
        Game_Menu(choix);

        //Initialisation  Fenetre
        sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "AIRPORT CONTROL SIMULATOR");
        window.setPosition(sf::Vector2i(0, 10));

        switch (choix) {
            case 1 :

                Sprite.setScale(
                        targetSize.x / Sprite.getLocalBounds().width,
                        targetSize.y / Sprite.getLocalBounds().height);

                window.clear(sf::Color::Transparent);

                while (!fin) {
                    sf::Event event{};
                    while (window.pollEvent(event)) {
                        Flight f{p.getListPlane(), a.getListAirport(), enter_manual};
                        f.Plane_Movement(window, Sprite,enter_manual);

                        if (event.type == sf::Event::Closed ||
                            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                            fin = true;
                            window.close();
                            choix = 0;
                        }
                    }
                }
                fin = false;

                break;
            case 2 :
                //affichage info aeroport
                airport_information(choix, a);
                choix=0;
                break;
            case 3:
                //affichage info avion
                airplane_information(choix, p);
                choix = 0;
                break;
            case 4 :
                back_menu = false;
                //Credits
                std::cout << "Credit";
                break;
            case 5 :
                std::cout << "Good bye HAVE A NICE DAY";
                break;
            default:
                std::cout << "UNKNOWN CHOICE\n"
                             "PLEASE RE-TYPE\n";
                choix = 0;
                break;
        }

    } while (choix < 5 && back_menu);
    return 0;
}


