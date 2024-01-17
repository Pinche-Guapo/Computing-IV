// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]

#include <string>
#include <sstream>
#include <SFML/Audio.hpp>
#include "universe.hpp" //NOLINT

template <typename T> std::string tString(const T &a) {
    std::ostringstream os;
    int year = a / 31536000;
    int afterY = a - (year * 31536000);
    int day = afterY / 86400;
    int hour = (a - day * 86400) / 3600;
    os << year << " years, " << day << " days, " << hour;
    os << " hours" << std::endl;
    return os.str();
}

int main(int argc, char* argv[]) {
        if (argc != 3) {
        std::cout << "Usage: ./NBody [double/ big t] " << std::endl;
        std::cout << "[double/ triangle t] < planets.txt " << std::endl;
        return 1;
    }

    std::string bigT(argv[1]);
    std::string triT(argv[2]);
    double simTime = 0;
    double bT = std::atoi(bigT.c_str());
    double tT = std::atoi(triT.c_str());

    universe* uni = new universe();

    std::cin >> *uni;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy");
    window.setFramerateLimit(120);

    sf::Font timeF;
    timeF.loadFromFile("arial.ttf");

    sf::Text timeT;
    timeT.setFont(timeF);
    timeT.setCharacterSize(12);
/*
    sf::Music music;
    if (!music.openFromFile("2001.ogg")) {
        std::cout << "cannot load the music" << std::endl;
        exit(1);
    }

    music.play();
    music.setLoop(true);
*/
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

        timeT.setString("Elapsed time: " + tString(simTime));
        window.draw(timeT);

        double forceX, forceY;

        std::vector<std::shared_ptr<CelestialBody>>::iterator a, b;
        for ( a = uni->cbVec.begin() ; a != uni->cbVec.end() ; a++ ) {
            forceX = 0;
            forceY = 0;
                for ( b = uni->cbVec.begin() ; b != uni->cbVec.end() ; b++ ) {
                    if (a != b) {
                        forceX += findForX(*(*a), *(*b));
                        forceY += findForY(*(*a), *(*b));
                    }
                    (*a)->setFor(forceX, forceY);
                }
        }

        std::vector<std::shared_ptr<CelestialBody>>::iterator it;
        for ( it = uni->cbVec.begin() ; it != uni->cbVec.end() ; it++ ) {
            window.draw(*(*it));
        }
        uni->step(tT);

        window.display();

        simTime += tT;
        if (simTime == bT) break;  // end
    }

    std::cout << std::endl << std::endl;
    std::cout << "Final State: \n";
    std::vector<std::shared_ptr<CelestialBody>>::iterator it;
    for (it = uni->cbVec.begin(); it != uni->cbVec.end(); it++) {
        std::cout << *(*it) << std::endl;
    }

    return 0;
}
