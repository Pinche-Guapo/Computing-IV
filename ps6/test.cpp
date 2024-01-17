// Copyright Jeongjae Han [UMASS LOWELL] [06/15/2022]

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "RandomWriter.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(t1) {
    RandWriter t("gagggagaggcgagaaa", 4);
    BOOST_REQUIRE(t.orderK() == 4);
    BOOST_REQUIRE_THROW(t.freq("layla"), std::runtime_error);
    BOOST_REQUIRE(t.freq("gagg") == 2);
    BOOST_REQUIRE(t.freq("gagg", 'g') == 1);

    BOOST_REQUIRE_NO_THROW(t.kRand("gagg"));
    BOOST_REQUIRE_THROW(t.kRand("layla"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(t2) {
    BOOST_REQUIRE_NO_THROW(RandWriter("asdfasdfasdfasdf", 0));

    RandWriter t("aaaaasssssdddddfffff", 0);

    BOOST_REQUIRE(t.orderK() == 0);

    BOOST_REQUIRE_THROW(t.freq("q"), std::runtime_error);
    BOOST_REQUIRE_THROW(t.freq("w"), std::runtime_error);

    BOOST_REQUIRE(t.freq("") == 20);
    BOOST_REQUIRE(t.freq("", 'a') == 5);
    BOOST_REQUIRE(t.freq("", 'e') == 0);
}
