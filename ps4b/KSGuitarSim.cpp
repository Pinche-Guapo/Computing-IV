// Copyright Jeongjae Han [Umass Lowell] [06/12/2022]
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "StringSound.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound& gs) {
    std::vector<sf::Int16> samples;

    gs.pluck();
    int duration = 8;  // seconds
    int i;
    for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
        gs.tick();
        samples.push_back(gs.sample());
    }
    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200), "KSGuitarSim");
    sf::Event event;
    std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

    double freq;

    std::vector<sf::Int16> samples[37];
    sf::Sound sound1[37];
    sf::SoundBuffer buf1[37];

    for (int i = 0; i < 37 ; i++) {
        freq = 440 * pow(2.0, (i-24) / 12.0);
        StringSound gs(freq);
        samples[i] = makeSamples(gs);
        // std::cout << samples[i].size() << std::endl;
        buf1[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, 44100);
        sound1[i].setBuffer(buf1[i]);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::TextEntered) {
                int i = keys.find(event.text.unicode);
                if (i >= 0 && i <= 36) {
                    sound1[i].play();
                }
            }
        }
        window.clear();
        window.display();
    }
    return 0;
}
