// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#include <vector>
#include <memory>
#include "universe.hpp"  //NOLINT

universe::universe() {
    return;
}

std::istream& operator>> (std::istream &in, universe &u) {
    std::string planetNum, radius;

    in >> planetNum;
    in >> radius;

    u.planetNum = atoi(planetNum.c_str());
    u.universeR = atof(radius.c_str());

    std::cout << "Number of planets: " << u.planetNum << std::endl;
    std::cout << "Radius: " << u.universeR << std::endl;

    for (int i = 0 ; i < u.planetNum; i++) {
        std::shared_ptr<CelestialBody> cb(new CelestialBody(u.universeR));
        in >> *cb;
        // cb->setRadius(cb->getPX() / u.universeR);
        cb->setPos();
        u.cbVec.push_back(cb);
        std::cout << *cb;
    }

    return in;
}

int universe::getPN() const {
    return planetNum;
}

CelestialBody universe::getPIndex(int index) {
    return *(cbVec[index]);
}


void universe::step(double seconds) {
    std::vector<std::shared_ptr<CelestialBody>>::iterator it, p;
    for (it = cbVec.begin(); it != cbVec.end(); it++) {
        (*it)->setAccX((*it)->getFX() / (*it)->getM());
        (*it)->setAccY((*it)->getFY() / (*it)->getM());

        (*it)->setVelX((*it)->getVX() + ((*it)->getAX() * seconds));
        (*it)->setVelY((*it)->getVY() - ((*it)->getAY() * seconds));

        (*it)->setPosX((*it)->getPX() + ((*it)->getVX() * seconds));
        (*it)->setPosY((*it)->getPY() - ((*it)->getVY() * seconds));

        (*it)->setPos();
    }
}


universe::~universe() {
    planetNum = 0;
    universeR = 0;
}
