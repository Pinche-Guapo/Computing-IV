// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#include "CelestialBody.hpp" //NOLINT

CelestialBody::CelestialBody() {}

CelestialBody::CelestialBody(double posiX, double posiY, double VeloX, \
    double veloY, double m, double r, std::string file) {
    posX = posiX;
    posY = posiY;
    velX = VeloX;
    velY = veloY;
    mass = m;

    if (!cbIm.loadFromFile(file)) {
        std::cout << "Cannot load the file" << std::endl;
        exit(1);
    }

    cbTex.loadFromImage(cbIm);
    cbSp.setTexture(cbTex);
    cbSp.setPosition(sf::Vector2f(posX, posY));
}

void CelestialBody::setRadius(float r) {
    radius = r;
}

void CelestialBody :: setPos() {
    double x = (windowWidth / 2.5) * (posX / radius);
    double y = (windowWidth / 2.5) * (posY / radius);

    cbSp.setPosition(x + (windowWidth / 2), y + (windowHeight / 2));
}

void CelestialBody::draw(sf::RenderTarget& target, \
        sf::RenderStates states) const {
    target.draw(cbSp);
}

std::istream& operator>> (std:: istream &in, CelestialBody &c) {
    in >> c.posX;
    in >> c.posY;
    in >> c.velX;
    in >> c.velY;
    in >> c.mass;
    in >> c.name;

    if (!c.cbIm.loadFromFile(c.name)) {
        std::cout << "Cannot load the file for Celestial Body" << std::endl;
        return in;
    }

    c.cbTex.loadFromImage(c.cbIm);
    c.cbSp.setTexture(c.cbTex);
    c.cbSp.setPosition(sf::Vector2f(c.posX, c.posY));

    return in;
}

std::ostream& operator<< (std::ostream &out, CelestialBody &c) {
    out << "Name of the Planet: " << c.name << std::endl;
    out << "Position x: " << c.posX << std::endl;
    out << "Position y: " << c.posY << std::endl;
    out << "Velocity x: " << c.velX << std::endl;
    out << "Velocity y: " << c.velY << std::endl;
    out << "Mass : " << c.mass << std::endl;
    return out;
}

CelestialBody::~CelestialBody() {
    posX = 0;
    posY = 0;
    velX = 0;
    velY = 0;
    mass = 0;
    name.clear();
}
