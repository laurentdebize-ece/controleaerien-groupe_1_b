#include "src/Menu/Menu.h"
#include "src/Flight/Flight.h"
#include <thread>
#include <iostream>
#include <memory>
#include <functional>

void rien(int x){
    //rien
}
//sf::RenderWindow window();

sf::RenderWindow *window = nullptr;



 void Turbulence() {

     if (window == nullptr) {

         window = new sf::RenderWindow(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "AIRPORT CONTROL SIMULATOR");

     }

     sf::Texture animTexture;
     if (!animTexture.loadFromFile("Graphic_Content/turbulence/Rain_animation.png")) {
         std::cout << "bullshit";
         //  return -1;
     }

     sf::Vector2i spriteSize(30, 30);//152 72

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
         animSprites[i].setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y / 2.0f);
     }

     int frameIndex = 0;
     float frameDuration = 0.4f; // Each frame takes aruond 1/10 sec.

     sf::Clock clock;

     while (window->isOpen()) {
         sf::Event event{};
         while (window->pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
                 window->close();
             }
         }

         if (clock.getElapsedTime().asSeconds() >= frameDuration) {
             frameIndex++;
             frameIndex = frameIndex % (int)(animSprites.size());

             clock.restart();
         }

         window->clear(sf::Color(0, 0, 0));
         window->draw(animSprites[frameIndex]);
         window->display();
     }
}

 int main() {
     unsigned int choix(0);
     bool fin(false), back_menu(true);
     //sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "AIRPORT CONTROL SIMULATOR");
     sf::Thread  nuage(Turbulence);



     sf::Font font;
     font.loadFromFile("Font/Pixeled.ttf");
     //Initialisation Cartes Map
     sf::Texture Menu_principal;

     Menu_principal.loadFromFile("Graphic_Content/Map/Sim_Map.png");

     sf::Sprite Sprite(Menu_principal);

     sf::Vector2f targetSize(LARGEUR_FENETRE, HAUTEUR_FENETRE);

     Plane p{"../Text_files/Airplane"};
     Aiport_network a{"../Text_files/Airport_network"};
     Flight f{p.getListPlane(),a.getListAirport()};

     do {
         Game_Menu(choix);

         //Initialisation  Fenetre

         window->setPosition(sf::Vector2i(0,10));


         switch (choix) {
                 case 1 :
                     nuage.launch();
                 /*for(;;)
                     std::cout << '.';*/
                 nuage.wait();
                    // Turbulence(window);
                    // std::thread first (rien,0);
                     //a.PCC(&f);// juste pour test pcc mais mon pc a planté wsv je veriffie si ça fonctione demain
                     /*Sprite.setScale(
                             targetSize.x / Sprite.getLocalBounds().width,
                             targetSize.y / Sprite.getLocalBounds().height);

                     window.clear(sf::Color::Transparent);

                     while (!fin) {
                         sf::Event event{};
                         while (window.pollEvent(event)) {

                             Plane_Movement(event, window, p, a, Sprite);

                             show_airport_on_screen(event, window, Sprite, a, font);
                             //a.show_airport_on_screen(event, window, Sprite);
                             //f.Flight_manual();
                             if (event.type == sf::Event::Closed ||
                                 (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
                                 fin = true;
                                 window.close();
                                 choix = 0;
                         }
                     }
                 }
                    fin = false;*/
                     //toutes les fonctions du simulateur
                     break;
                 case 2 :
                     //toutes les fonctions affichage aeroport
                     airport_information(choix,a);
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
                     std::cout<<"UNKNOWN CHOICE\n"
                                "PLEASE RE-TYPE\n";
                     choix=0;
                     break;
             }

         }while (choix < 5 && back_menu);
     return 0;
}


