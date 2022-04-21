#include "src/Airport/Airport.h"



 int main() {
     unsigned int choix(0);
     bool fin(false), back_menu(true);

     //Initialisation Cartes Map
     sf::Texture Menu_principal;

     Menu_principal.loadFromFile("../Graphic_content/Map/Sim_Map.png");

     sf::Sprite Sprite(Menu_principal);

     sf::Vector2f targetSize(LARGEUR_FENETRE, HAUTEUR_FENETRE);

     Plane p{"../Text_files/Airplane"};
     do {
         Game_Menu(choix);

         //Initialisation  Fenetre
         sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "AIRPORT CONTROL SIMULATOR");

         switch (choix) {
                 case 1 :
                     Sprite.setScale(
                             targetSize.x / Sprite.getLocalBounds().width,
                             targetSize.y / Sprite.getLocalBounds().height);

                     window.clear(sf::Color::Black);
                     while (!fin) {
                         sf::Event event{};
                         while (window.pollEvent(event)) {
                             show_airport_on_screen( event, window, Sprite);
                             if (event.type == sf::Event::Closed ||
                                 (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
                                 fin = true;
                                 window.close();
                                 choix = 0;
                             }
                         }
                     }
                    fin = false;
                     //toutes les fonctions du simulateur
                     break;
                 case 2 :
                     //toutes les fonctions du simulateur
                     break;
                 case 3:
                     //toutes les fonctions affichage avion
                     airplane_information(choix,p);
                     choix=0;
                     break;
                 case 4 :
                     back_menu= false;
                     //Credits
                     std::cout <<"Credit";
                     break;
                 case 5 :
                     std::cout <<"Good bye HAVE A NICE DAY";
                     break;
                 default:
                     std::cout<<"Choix inconnu\n"
                                "Veuillez retaper\n";
                     choix=0;
                     break;
             }

         }while (choix < 5 && back_menu);
     return 0;
}


