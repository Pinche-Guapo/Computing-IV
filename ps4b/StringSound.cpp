// Copyright Jeongjae Han [Umass Lowell] [06/11/2022]
#include "StringSound.hpp"

StringSound::StringSound(double frequency): \
        cb((ceil(rate / frequency))) {
    // cb = new CircularBuffer(static_cast<size_t> (ceil(44100 / frequency)));
    if (frequency <= 0) throw std::invalid_argument\
            ("Frequency must be higher than 0.");

    t = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init): \
        cb(static_cast<size_t> (init.size())) {
    std::vector<sf::Int16>::iterator it;
    for (it = init.begin(); it < init.end(); it++) {
        cb.enqueue((int16_t)*it);
    }

    t = 0;
}

void StringSound::pluck() {
    while (!cb.isEmpty()) {
        cb.dequeue();
    }

    while (!cb.isFull()) {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> \
        distribution(-32768, 32767);
        sf::Int16 ranDom = distribution(rng);
        cb.enqueue(ranDom &0xffff);
    }
}

void StringSound::tick() {
    int16_t first = cb.dequeue();
    int16_t second = cb.peek();
    int16_t karplus = decay * [&] {return (first + second) / 2;}();

    cb.enqueue((sf::Int16)karplus);
    t++;
}

sf::Int16 StringSound::sample() const {
    sf::Int16 sample = (sf::Int16)cb.peek();

    return sample;
}

size_t StringSound::time() const {
    return t;
}

StringSound::~StringSound() {
    // cb.~CircularBuffer();
    t = 0;
}
