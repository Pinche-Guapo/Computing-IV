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

CelestialBody::CelestialBody(double r) {
    radius = r;
}

void CelestialBody::setRadius(float r) {
    radius = r;
}

void CelestialBody::setPos() {
    double x = (windowWidth / 2.5) * (posX / radius);
    double y = (windowWidth / 2.5) * (posY / radius);

    cbSp.setPosition(x + (windowWidth / 2), y + (windowHeight / 2));
}

double CelestialBody::getFX() const {
    return forX;
}

double CelestialBody::getFY() const {
    return forY;
}

double CelestialBody::getM() const {
    return mass;
}

double CelestialBody::getVX() const {
    return velX;
}

double CelestialBody::getVY() const {
    return velY;
}

double CelestialBody::getPX() const {
    return posX;
}

double CelestialBody::getPY() const {
    return posY;
}

double CelestialBody::getAX() const {
    return accX;
}

double CelestialBody::getAY() const {
    return accY;
}

double CelestialBody::getR() const {
    return radius;
}

std::string CelestialBody::getN() const {
    return name;
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

    c.setAccX(0.f);
    c.setAccY(0.f);

    c.setFor(0.f, 0.f);

    return in;
}

std::ostream& operator<< (std::ostream &out, CelestialBody &c) {
    out << "Name of the Planet: " << c.name << std::endl;
    out << "Position x: " << c.posX << std::endl;
    out << "Position y: " << c.posY << std::endl;
    out << "Velocity x: " << c.velX << std::endl;
    out << "Velocity y: " << c.velY << std::endl;
    out << "Mass : " << c.mass << std::endl;
    out << "Accelaration X: " << c.accX << std::endl;
    out << "Accelaration Y: " << c.accY << std::endl;
    out << "Force X: " << c.forX << std::endl;
    out << "Force Y: " << c.forY << std::endl;
    out << "Radius: " << c.radius << std::endl << std::endl;
    return out;
}

double findForX(CelestialBody &sun, CelestialBody &p) {
    double x, y, r2, root, force, forX, radius;
    /*if (p.posY == 0) {
        radius = p.posX - sun.posX;
        force = gravity * sun.mass * p.mass / pow(radius, 2);

    }*/

    x = p.posX - sun.posX;
    y = p.posY - sun.posY;

    r2 = pow(x, 2) + pow(y, 2);
    root = sqrt(r2);

    // F = (g * m1 * m2) / R^2;
    force = (gravity * sun.mass * p.mass) / r2;
    forX = force * (x / root);

    return forX;
}

double findForY(CelestialBody &sun, CelestialBody &p) {
    double x, y, r2, root, force, forY, radius;

    x = p.posX - sun.posX;
    y = p.posY - sun.posY;

    r2 = pow(x, 2) + pow(y, 2);
    root = sqrt(r2);
    // F = (g * m1 * m2) / r^2
    force = (gravity * sun.mass * p.mass) / r2;
    forY = force * (y / root);

    return forY;
}

void CelestialBody::setFor(double fX, double fY) {
    forX = fX;
    forY = fY;
}

void CelestialBody::setAccX(double a) {
    accX = a;
}

void CelestialBody::setAccY(double a) {
    accY = a;
}

void CelestialBody::setVelX(double a) {
    velX = a;
}

void CelestialBody::setVelY(double a) {
    velY = a;
}

void CelestialBody::setPosX(double a) {
    posX = a;
}

void CelestialBody::setPosY(double a) {
    posY = a;
}

CelestialBody::~CelestialBody() {
    posX = 0;
    posY = 0;
    velX = 0;
    velY = 0;
    mass = 0;
    accX = 0;
    accY = 0;
    forX = 0;
    forY = 0;
    name.clear();
}
