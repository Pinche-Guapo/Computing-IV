// Copyright Jeongjae Han [UMASS LOWELL] [06/15/2022]
#include "RandomWriter.hpp"

RandWriter::RandWriter(std::string text, int n): order(n) {
    // Create a Markov model of order k from given text
    // Assume that text has length at least k.

    std::string str = text;

    for ( int i = 0; i < order; i++ ) {
        str.push_back(text[i]);
    }

    char temp;
    bool taken = false;

    for (size_t i = 0; i < text.length(); i++) {
        temp = text.at(i);
        taken = false;
        for (size_t j = 0; j < alphabet.length(); j++) {
            if (alphabet.at(j) == temp) taken = true;
        }
        if (!taken) alphabet.push_back(temp);
    }

    std::string tempStr;

    for (int i = order; i <= order + 1; i++) {
        for (size_t j = 0; j < text.length(); j++) {
            tempStr.clear();
            tempStr = str.substr(j, i);

            kMap.insert(std::pair<std::string, int>(tempStr, 0));
        }
    }

    int count = 0;

    for (int i = order; i <= order + 1; i++) {
        for (size_t j = 0; j < text.length(); j++) {
            tempStr.clear();
            tempStr = str.substr(j, i);

            auto p = kMap.find(tempStr);
            count = p->second;
            count++;

            kMap[tempStr] = count;
        }
    }
}

int RandWriter::orderK() const {
     return order;
}

int RandWriter::freq(std::string kgram) const {
    if (kgram.size() == static_cast<size_t>(order)) {
        auto p = kMap.find(kgram);

        if (p == kMap.end()) return 0;

        return p->second;
    } else {
        throw std::runtime_error\
            ("for frequency, provided string is not right size.");
    }
}

int RandWriter::freq(std::string kgram, char c) const {
    if (kgram.size() == static_cast<size_t>(order)) {
        kgram.push_back(c);
        auto p = kMap.find(kgram);
        if (p == kMap.end()) {
            return 0;
        } else {
            return p->second;
        }
    } else {
        throw std::runtime_error\
            ("for frequency2, provided string is not right");
    }
}

char RandWriter::kRand(std::string kgram) {
    if (kgram.length() != static_cast<size_t>(order))\
        throw std::runtime_error\
        ("for krand your kgram is wrong");

    srand((int)time(NULL));  // NOLINT

    int kgramF = freq(kgram);
    int ranVal = rand() % kgramF; //NOLINT
    double test = 0;
    auto creatRan = [=] () \
        {return static_cast<double>(ranVal) / kgramF; };
    double ranNum = creatRan();
    double lVal = 0;

    for (size_t i = 0; i < alphabet.length(); i++) {
        test = static_cast<double> \
            (freq(kgram, alphabet[i])) / kgramF;

        if ((ranNum < (test + lVal)) && test != 0) {
            return alphabet[i];
        }
        lVal += test;
    }
    return 0;
}

std::string RandWriter::generate(std::string kgram, int L) {
    if (kgram.length() != static_cast<size_t>(order)) throw std::runtime_error\
        ("generate string kgram is wrong");

    std::string finStr = "";
    char retChar;

    finStr += "" + kgram;

    for ( int i = 0 ; i < (L - order); i++ ) {
        retChar = kRand(finStr.substr(i, order));
        finStr.push_back(retChar);
    }
    return finStr;
}

std::string RandWriter::getA() const {
    return alphabet;
}

auto RandWriter::begin() const {
    return kMap.begin();
}

auto RandWriter::end() const {
    return kMap.end();
}

std::ostream& operator<< (std::ostream &out, RandWriter &rw) {
    out << "Order: " << rw.orderK() << std::endl;
    out << "Alphabet: " << rw.getA() << std::endl;
    out << "Map: ";

    for (auto p = rw.begin(); p != rw.end(); p++) {
        out << p->first << "\t" << p->second << std::endl;
    }
    return out;
}

RandWriter::~RandWriter() {
    order = 0;
    alphabet.clear();
}
