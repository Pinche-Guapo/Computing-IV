std::istream& operator>> (std::istream &in, universe &u) {
    std::string planetNum, radius;

    in >> planetNum;
    in >> radius;

    u.planetNum = atoi(planetNum.c_str());
    u.universeR = atof(radius.c_str());

    std::cout << "Number of planets: " << u.planetNum << std::endl;
    std::cout << "Radius: " << u.universeR << std::endl;

    for (int i = 0 ; i < u.planetNum; i++) {
        CelestialBody* cb = new CelestialBody();
        in >> *cb;
        cb->setRadius(u.universeR);
        cb->setPos();
        u.cbVec.push_back(*cb);
        std::cout << *cb;
    }

    return in;
}

