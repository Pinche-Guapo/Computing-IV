// Copyright Jeongjae Han [Umass Lowell] [06/09/2022]
#include <iostream>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include "CircularBuffer.hpp"
#include "StringSound.hpp"

BOOST_AUTO_TEST_CASE(throw1) {  // testing throw
    BOOST_REQUIRE_NO_THROW(CircularBuffer <size_t> (2));
    BOOST_REQUIRE_NO_THROW(CircularBuffer <size_t> (1));

    BOOST_REQUIRE_THROW(CircularBuffer <size_t> (0), std::invalid_argument);
    BOOST_REQUIRE_THROW(CircularBuffer <size_t> (0), std::exception);
}

BOOST_AUTO_TEST_CASE(size) {  // size() test
    CircularBuffer <size_t> t(2);
    t.enqueue(1);
    BOOST_REQUIRE_EQUAL(t.size(), 1);
    t.enqueue(2);
    BOOST_REQUIRE_EQUAL(t.size(), 2);
}

BOOST_AUTO_TEST_CASE(empty) {  // empty test
    CircularBuffer <size_t> t(1);
    t.enqueue(1);
    t.dequeue();
    BOOST_REQUIRE(t.isEmpty() == true);
}

BOOST_AUTO_TEST_CASE(full) {  // full test
    CircularBuffer <size_t> t(1);
    BOOST_REQUIRE(t.isFull() == false);
    t.enqueue(1);
    BOOST_REQUIRE(t.isFull() == true);
}

BOOST_AUTO_TEST_CASE(enqueue) {  // checking enqueue function errors
    CircularBuffer <size_t> t(1);
    BOOST_REQUIRE_NO_THROW(t.enqueue(1));
    BOOST_REQUIRE_THROW(t.enqueue(1), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(dequeue) {  // dequeue() test
    CircularBuffer <size_t> t(1);
    t.enqueue(1);
    BOOST_REQUIRE(t.dequeue() == 1);
    BOOST_REQUIRE_THROW(t.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(peek) {
    CircularBuffer <size_t> t(3);
    t.enqueue(4);
    t.enqueue(1);
    BOOST_REQUIRE_EQUAL(t.peek(), 4);
}

BOOST_AUTO_TEST_CASE(const1) {  // check constructor
    BOOST_REQUIRE_NO_THROW(StringSound(2));
    BOOST_REQUIRE_NO_THROW(StringSound \
        t(std::vector<sf::Int16> init = {1, 2, 3}));
    BOOST_REQUIRE_THROW(StringSound(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(time1) {  // time check
    StringSound t(3.f);
    BOOST_REQUIRE_EQUAL(t.time(), 0);
}

BOOST_AUTO_TEST_CASE(sample1) {
    std::vector<sf::Int16> init = {1, 2, 3};
    StringSound t(init);
    BOOST_REQUIRE_EQUAL(t.sample(), 1);
}

BOOST_AUTO_TEST_CASE(pluck1) {  // pluck
    std::vector<sf::Int16> init = {1, 2, 3};
    StringSound t(init);
    t.pluck();
    BOOST_REQUIRE_NE(t.sample(), 1);
}

BOOST_AUTO_TEST_CASE(tic) {  // tic()
    std::vector<sf::Int16> init = {1, 2, 3};
    StringSound t(init);
    t.tick();
    BOOST_REQUIRE_EQUAL(t.time(), 1);
}
