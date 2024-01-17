// Copyright Jeongjae Han [Umass Lowell] [06/09/2022]
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>

template <class T>
class CircularBuffer {
 public:
    explicit CircularBuffer(size_t capacity) {
        // Create an empty ring buffer with given max capacity
        if ( capacity < 1 ) {
            throw std::invalid_argument\
            ("Capacity must be bigger than 0.");
        } else {
            beg = 0;
            end = 0;
            cap = capacity;
            si = 0;
            cbVec.resize(capacity);
        }
    }

    size_t size() const {  // The number of items currently in the buffer
        return si;
    }

    bool isEmpty() const {  // Is the buffer is empty?
        if (si == 0 ) return true;
        return false;
    }

    bool isFull() const {  // Is the buffer full?
        if (si == cap) return true;
        return false;
    }

    void enqueue(T item) {  // Add item to the end
        if (isFull()) throw std::runtime_error("The buffer is full");

        if (end >= cap) end = 0;
        cbVec.at(si) = item;
        si++;
        end++;
    }

    T dequeue() {  // Delete and return item from the front
        if (isEmpty()) throw std::runtime_error\
            ("The buffer is already empty: dequeue()");

        T item = cbVec.at(beg);
        cbVec.at(beg) = 0;
        beg++;
        si--;
        if (beg >= cap) beg = 0;

        return item;
    }

    T peek() const {  // Return (but do not delete) item from the front
        if (isEmpty()) throw std::runtime_error\
            ("The buffer is empty: no peek()");
        return cbVec.at(beg);
    }

    ~CircularBuffer() {
        cbVec.clear();
        beg = 0;
        end = 0;
        cap = 0;
        si = 0;
    }

 private:
    std::vector<T> cbVec;
    int beg;  // first index
    int end;  // last index
    int cap;
    int si;
};
