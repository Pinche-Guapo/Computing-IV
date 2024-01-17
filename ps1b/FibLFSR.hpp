#pragma once
#include <iostream>
#include <string>

using namespace std;

class FibLFSR {
public:
    // Constructor to create LFSR with the given initial seed
    FibLFSR(std::string seed);
    string getSeed() const { return iSeed; }
    void setSeed(string seed) { iSeed = seed; }
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);

    ~FibLFSR();

private:
    // Any fields that you need
    string iSeed;
};

ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);


