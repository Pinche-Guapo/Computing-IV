// Copyright Jeongjae Han [Umass Lowell] [06/11/2022]
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "CircularBuffer.hpp"

const int rate = 44100;
const double decay = 0.996;

class StringSound {
 public:
    explicit StringSound(double frequency);
      // Create a guitar string sound of the given
      // frequency using a sampling rate of 44,100
    explicit StringSound(std::vector<sf::Int16> init);
      // Create a guitar string with size and initial values given by the vector
    StringSound(const StringSound& obj) = delete;  // No copy constructor
    void pluck();
      // Pluck the guitar string by replacing the buffer with random values,
      // representing the white noise
    void tick();  // Advance the simulation one time step
    sf::Int16 sample() const;  // Return the current sample
    size_t time() const;  // Return the number of times tick was called so far
    ~StringSound();

 private:
    CircularBuffer<size_t> cb;
    int t;
};
