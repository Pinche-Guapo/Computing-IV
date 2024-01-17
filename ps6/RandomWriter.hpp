// Copyright Jeongjae Han [UMASS LOWELL] [06/15/2022]
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <random>
#include <algorithm>
#include <utility>

class RandWriter {
 public:
    // Create a Markov model of order k from given text
    // Assume that text has length at least k.
    RandWriter(std::string text, int k);
    int orderK() const;  // Order k of Markov model
    // Number of occurences of kgram in text
    // Throw an exception if kgram is not length k
    int freq(std::string kgram) const;
    // Number of times that character c follows kgram
    // if order=0, return num of times that char c appears
    // (throw an exception if kgram is not of length k)
    int freq(std::string kgram, char c) const;
    // Random character following given kgram
    // (throw an exception if kgram is not of length k)
    // (throw an exception if no such kgram)
    char kRand(std::string kgram);
    // Generate a string of length L characters by simulating a trajectory
    // through the corresponding Markov chain.  The first k characters of
    // the newly generated string should be the argument kgram.
    // Throw an excpetion if kgram is not of length k.
    // Assume that L is at least k
    std::string getA() const;
    std::string generate(std::string kgram, int L);
    friend std::ostream& operator<<(std::ostream& out, const RandWriter &r);

    auto begin() const;
    auto end() const;
    ~RandWriter();

 private:
    int order;
    std::string alphabet;
    std::map <std::string, int> kMap;
};
// Overload the stream insertion operator << and display the internal state
// of the Markov model.  Print out the order, alphabet, and the frequencies
// of the k-grams and k+1-grams
