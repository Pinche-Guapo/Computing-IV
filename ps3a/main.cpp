// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]

#include "universe.hpp" //NOLINT

int main(int argc, char* argv[]) {
    universe* uni = new universe();

    std::cin >> *uni;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy");
    window.setFramerateLimit(60);

    sf::Texture laylaTex;
    laylaTex.loadFromFile("Layla.jpg");
    if (!laylaTex.loadFromFile("Layla.jpg")) {  // Background image
     std::cout << "Cannot load Layla.jpg" << std::endl;
        exit(1);
    }

    sf::Sprite laylaSp;
    laylaSp.setTexture(laylaTex);
    laylaSp.setPosition(sf::Vector2f(0, 0));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(laylaSp);  // Draws Layla in the backgroud
        std::vector<CelestialBody>::iterator p;
        for (p = uni->cbVec.begin(); p != uni->cbVec.end(); p++) {
            window.draw(*p);
        }
        window.display();
    }

    return 0;
}
