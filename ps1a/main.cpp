// Copyright Jeongjae Han [Umass Lowell] [6/8/2022]
#include <iostream>
#include <string>
#include "FibLFSR.hpp"

int main() {
    FibLFSR flfsr("1011011000110110");

    int output = 0;
    for (int i = 0; i < 10; i++) {
        output = flfsr.step();
        std::cout << flfsr << '\t' << output << std::endl;
    }

    std::cout << "\n\n";

    FibLFSR flfsr1("1011011000110110");
    for (int i = 0; i < 7; i++) {
        output = flfsr1.generate(5);
        std::cout << flfsr1 << '\t' << output << std::endl;
    }

    FibLFSR l3("0111011000110110");
    l3.step();
    std::cout << l3.getSeed() << std::endl;

    FibLFSR l4("0111011000110110");
    l4.generate(6);
    std::cout << l4.getSeed() << std::endl;

    return 0;
}
