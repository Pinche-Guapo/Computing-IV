// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const int windowHeight = 500;
const int windowWidth = 500;

class CelestialBody: public sf::Drawable {
 public:
    CelestialBody();
    CelestialBody(double posiX,  double posiY, double veloX, \
        double veloY, double m, double r, std::string file);

    void setRadius(float radius);
    void setPos();

    friend std::istream& operator>> (std::istream &in, CelestialBody &c);
    friend std::ostream& operator<< (std::ostream &out, CelestialBody &c);

    ~CelestialBody();

 private:
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

    double posX;
    double posY;
    double velX;
    double velY;
    double mass;
    double radius;
    std::string name;

    sf::Image cbIm;
    sf::Sprite cbSp;
    sf::Texture cbTex;
};
