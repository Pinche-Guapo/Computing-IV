// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CelestialBody.hpp"  //NOLINT
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class universe {
 public:
    universe();

    friend std::istream& operator>> (std::istream &in, universe &u);

    std::vector<CelestialBody> cbVec;
    ~universe();
 private:
    int planetNum;
    double universeR;
};
