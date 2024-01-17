// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(l) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
}

BOOST_AUTO_TEST_CASE(l2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 236);
}

BOOST_AUTO_TEST_CASE(l3){
  FibLFSR l3("0111011000110110");
  BOOST_REQUIRE_EQUAL(l3.step(),0);
}

BOOST_AUTO_TEST_CASE(l4){
  FibLFSR l4("0111011000110110");
  BOOST_REQUIRE_EQUAL(l4.generate(6), 29);
}

BOOST_AUTO_TEST_CASE(b1){
  FibLFSR b1("jason");
  BOOST_REQUIRE_EQUAL(b1.getSeed(), "0000001000011011");
}

BOOST_AUTO_TEST_CASE(b2){
  FibLFSR b2("1234");
  BOOST_REQUIRE_EQUAL(b2.getSeed(), "0000000011001010");
}


