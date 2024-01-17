// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const int windowHeight = 500;
const int windowWidth = 500;
const double gravity = 6.67e-11;

class CelestialBody: public sf::Drawable {
 public:
    CelestialBody();
    CelestialBody(double posiX,  double posiY, double veloX, \
        double veloY, double m, double r, std::string file);
    CelestialBody(double r); //NOLINT
    void setRadius(float radius);
    void setPos();
    double getFX() const;
    double getFY() const;
    double getM() const;
    double getVX() const;
    double getVY() const;
    double getPX() const;
    double getPY() const;
    double getAX() const;
    double getAY() const;
    double getR() const;
    std::string getN() const;
    friend std::istream& operator>> (std::istream &in, CelestialBody &c);
    friend std::ostream& operator<< (std::ostream &out, CelestialBody &c);

    friend double findForX(CelestialBody &sun, CelestialBody &p);
    friend double findForY(CelestialBody &sun, CelestialBody &p);
    void setFor(double fX, double fY);
    void setAccX(double a);
    void setAccY(double a);
    void setVelX(double a);
    void setVelY(double a);
    void setPosX(double a);
    void setPosY(double a);

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
    double accX;
    double accY;
    double forX;
    double forY;

    sf::Image cbIm;
    sf::Sprite cbSp;
    sf::Texture cbTex;
};
