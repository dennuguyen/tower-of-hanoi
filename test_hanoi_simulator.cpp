#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hanoi_simulator.hpp"

TEST_SUITE("Initialising simulator.") {
    TEST_CASE("Pegs within valid range.") {
        CHECK_NOTHROW(hanoi_simulator({1, 2, 3}, 3));
    }

    TEST_CASE("Peg less than 1.") {
        CHECK_THROWS_AS(hanoi_simulator({1, 2, 0}, 3), std::invalid_argument);
    }

    TEST_CASE("Peg greater than num_pegs.") {
        CHECK_THROWS_AS(hanoi_simulator({1, 2, 4}, 3), std::invalid_argument);
    }
}

TEST_SUITE("Moving discs.") {
    TEST_CASE("Moving smaller disc on top of larger disc should return true.") {
        auto hs = hanoi_simulator({1, 2, 3}, 3);
        CHECK(hs.move(3, 2) == true);
        CHECK(hs.move(2, 1) == true);
        CHECK(hs.move(1, 3) == true);
    }

    TEST_CASE("Moving discs should have correct state.") {
        auto hs = hanoi_simulator({1, 2, 3}, 3);
        REQUIRE(hs.move(3, 2) == true);
        CHECK(std::vector<int>(hs) == std::vector<int>({1, 2, 2}));
        REQUIRE(hs.move(2, 1) == true);
        CHECK(std::vector<int>(hs) == std::vector<int>({1, 2, 1}));
        REQUIRE(hs.move(1, 3) == true);
        CHECK(std::vector<int>(hs) == std::vector<int>({1, 2, 3}));
        REQUIRE(hs.move(2, 1) == true);
        CHECK(std::vector<int>(hs) == std::vector<int>({1, 1, 3}));
        REQUIRE(hs.move(3, 1) == true);
        CHECK(std::vector<int>(hs) == std::vector<int>({1, 1, 1}));
    }

    TEST_CASE("Moving from peg with no discs should throw.") {
        auto hs = hanoi_simulator({1, 1, 3}, 4);
        CHECK_THROWS_AS(hs.move(2, 1), std::logic_error);
        CHECK_THROWS_AS(hs.move(4, 3), std::logic_error);
    }

    TEST_CASE("Moving larger disc on top of smaller disc should throw.") {
        auto hs = hanoi_simulator({1, 2, 3}, 3);
        CHECK_THROWS_AS(hs.move(1, 2), std::logic_error);
        CHECK_THROWS_AS(hs.move(1, 3), std::logic_error);
    }

    TEST_CASE("Moving disc to itself should return false.") {
        auto hs = hanoi_simulator({1, 2, 3}, 3);
        CHECK(hs.move(1, 1) == false);
        CHECK(hs.move(2, 2) == false);
        CHECK(hs.move(3, 3) == false);
    }
}
