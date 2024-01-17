// Copyright Jeongjae Han [UMASS LOWELL] [06/15/2022]

#include <iostream>
#include <string>
#include "RandomWriter.hpp"

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        std::cout << "Format ./TextWriter [number for K] [number for L] \n";
        exit(1);
    }

    int k = std::stoi(argv[1]);
    int l = std::stoi(argv[2]);

    std::string input;
    std::string text;

    while (std::getline(std::cin, text)) {
        input.append(text);
        input.append(1, ' ');
    }

    RandWriter rw(input, k);
    // std::cout << "Number of 'ga': " << rw.freq("ga") << std::endl;
    // std::cout << "Number of 'gc': " << rw.freq("gc") << std::endl;
    // std::cout << "Number of 'ab': " << rw.freq("ab") << std::endl;
    // std::cout << "Random character produced: " << rw.kRand("ga") << std::endl;
    std::cout << rw.generate(input.substr(0, k), l) << std::endl;
}
