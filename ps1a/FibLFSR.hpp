// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#pragma once
#include <iostream>
#include <string>

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed) : iSeed(seed) {}
    std::string getSeed() const;
    void setSeed(std::string seed);
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);

    ~FibLFSR();

 private:
    // Any fields that you need
    std::string iSeed;
};

std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);