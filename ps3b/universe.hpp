// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CelestialBody.hpp"  //NOLINT
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class universe:public sf::Drawable {
 public:
    universe();

    friend std::istream& operator>> (std::istream &in, universe &u);
    std::vector<std::shared_ptr<CelestialBody>> cbVec;
    CelestialBody getPIndex(int index);
    void step(double seconds);

    int getPN() const;

    ~universe();
 private:
    int planetNum;
    double universeR;
    void virtual draw(sf::RenderTarget& target, \
      sf::RenderStates states) const {}
};
