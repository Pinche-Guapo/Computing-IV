// Copyright Jeongjae Han [Umass Lowell] [6/2/2022]
#include "FibLFSR.hpp"

std::string FibLFSR::getSeed() const {
    return iSeed;
}

void FibLFSR::setSeed(std::string seed) {
    iSeed = seed;
}

int FibLFSR::step() {
    std::string aSeed = getSeed();
    int output;
    std::string out;

    // addition works as xor
    output = (aSeed.at(0) + aSeed.at(2) + aSeed.at(3) + aSeed.at(5)) & 0x00001;
    aSeed.erase(aSeed.begin());

    // changing the output to string
    if (output == 1) out = "1";
    else if (output == 0) out = "0";
    aSeed = aSeed + out;
    setSeed(aSeed);

    return output;
}


int FibLFSR::generate(int k) {
        int result = 0;
        for (int i = 0; i < k; i++) {
            result *= 2;
            result += step();
        }
        return result;
    }

std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    out << lfsr.getSeed();
    return out;
}

FibLFSR::~FibLFSR() {
    iSeed.clear();
}
