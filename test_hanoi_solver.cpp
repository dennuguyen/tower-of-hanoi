#include <experimental/iterator>
#include <iostream>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hanoi_simulator.hpp"
#include "hanoi_solver.hpp"

TEST_CASE("3 Pegs.") {
    auto num_pegs = 3;
    auto initial = std::vector<int>();
    auto final = std::vector<int>();

    SUBCASE("[1, 1, 1] -> [1, 1, 1]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({1, 1, 1});
    }

    SUBCASE("[1, 1, 1] -> [2, 2, 2]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({2, 2, 2});
    }

    SUBCASE("[1, 1, 1] -> [3, 3, 3]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({3, 3, 3});
    }

    SUBCASE("[1, 1, 1] -> [1, 2, 3]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({1, 2, 3});
    }

    SUBCASE("[1, 1, 1, 1] -> [2, 1, 2, 3]") {
        initial = std::vector<int>({1, 1, 1, 1});
        final = std::vector<int>({2, 1, 2, 3});
    }

    SUBCASE("[1, 1, 1, 1] -> [3, 3, 3, 3]") {
        initial = std::vector<int>({1, 1, 1, 1});
        final = std::vector<int>({3, 3, 3, 3});
    }

    SUBCASE("[1, 1, 1, 1] -> [3, 3, 3, 2]") {
        initial = std::vector<int>({1, 1, 1, 1});
        final = std::vector<int>({3, 3, 3, 2});
    }

    SUBCASE("[1, 1, 1, 1, 1] -> [3, 3, 1, 2, 3]") {
        initial = std::vector<int>({1, 1, 1, 1, 1});
        final = std::vector<int>({3, 3, 1, 2, 3});
    }

    SUBCASE("[2, 1, 3, 2, 1] -> [1, 3, 1, 2, 1]") {
        initial = std::vector<int>({2, 1, 3, 2, 1});
        final = std::vector<int>({1, 3, 1, 2, 1});
    }

    SUBCASE("[3, 1, 3, 1, 1, 3, 2] -> [2, 2, 2, 2, 2, 2, 2]") {
        initial = std::vector<int>({3, 1, 3, 1, 1, 3, 2});
        final = std::vector<int>({2, 2, 2, 2, 2, 2, 2});
    }

    hanoi(initial, final);
    auto hs = hanoi_simulator(initial, num_pegs);
    for (auto const& i : moves) {
        hs.move(i.first, i.second);
    }

    CHECK(std::vector<int>(hs) == final);

    moves.clear();
}

TEST_CASE("4 Pegs.") {
    auto num_pegs = 4;
    auto initial = std::vector<int>();
    auto final = std::vector<int>();
    auto pegs = std::set<int>({1, 2, 3, 4});

    SUBCASE("[1, 1, 1] -> [2, 1, 4]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({2, 1, 4});
    }

    SUBCASE("[1, 1, 1] -> [4, 1, 2]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({4, 1, 2});
    }

    SUBCASE("[1, 1, 1, 1] -> [1, 1, 2, 1]") {
        initial = std::vector<int>({1, 1, 1, 1});
        final = std::vector<int>({1, 1, 2, 1});
    }

    SUBCASE("[1, 1, 1, 1, 1] -> [3, 3, 3, 3, 3]") {
        initial = std::vector<int>({1, 1, 1, 1, 1});
        final = std::vector<int>({3, 3, 3, 3, 3});
    }

    SUBCASE("[1, 1, 1, 1, 1, 1, 1] -> [2, 2, 2, 2, 2, 2, 2]") {
        initial = std::vector<int>({1, 1, 1, 1, 1, 1, 1});
        final = std::vector<int>({2, 2, 2, 2, 2, 2, 2});
    }

    SUBCASE("[1, 1, 1, 1, 1, 1, 1] -> [4, 4, 4, 4, 4, 4, 4]") {
        initial = std::vector<int>({1, 1, 1, 1, 1, 1, 1});
        final = std::vector<int>({4, 4, 4, 4, 4, 4, 4});
    }

    SUBCASE("[1, 1, 1] -> [2, 3, 4]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({2, 3, 4});
    }

    SUBCASE("[1, 1, 1, 1, 1, 1] -> [4, 3, 1, 4, 2, 3]") {
        initial = std::vector<int>({1, 1, 1, 1, 1, 1});
        final = std::vector<int>({4, 3, 1, 4, 2, 3});
    }

    SUBCASE("[4, 3, 2, 4, 3, 2, 4] -> [1, 4, 2, 3, 1, 4, 1]") {
        initial = std::vector<int>({4, 3, 2, 4, 3, 2, 4});
        final = std::vector<int>({1, 4, 2, 3, 1, 4, 1});
    }

    SUBCASE("[1, 1, 1] -> [4, 4, 4]") {
        initial = std::vector<int>({1, 1, 1});
        final = std::vector<int>({4, 4, 4});
    }

    SUBCASE("[1, 1, 1, 4, 4, 4, 1, 1, 1, 4, 4, 4] -> [2, 2, 2, 3, 1, 3, 4, 2, 3, 4, 2, 1]") {
        initial = std::vector<int>({1, 1, 1, 4, 4, 4, 1, 1, 1, 4, 4, 4});
        final = std::vector<int>({2, 2, 2, 3, 1, 3, 4, 2, 3, 4, 2, 1});
    }

    hanoi(initial, final, pegs);
    auto hs = hanoi_simulator(initial, num_pegs);
    for (auto const& i : moves) {
        hs.move(i.first, i.second);
    }

    CHECK(std::vector<int>(hs) == final);

    moves.clear();
}

TEST_CASE("5 Pegs.") {
    auto num_pegs = 5;
    auto initial = std::vector<int>();
    auto final = std::vector<int>();
    auto pegs = std::set<int>({1, 2, 3, 4, 5});

    SUBCASE("[1, 1, 1, 1, 1] -> [5, 5, 5, 5, 5]") {
        initial = std::vector<int>({1, 1, 1, 1, 1});
        final = std::vector<int>({5, 5, 5, 5, 5});
    }

    SUBCASE("[1, 1, 5, 1, 1, 4, 5, 3, 1, 3, 2, 2, 1, 4] -> [4, 3, 1, 4, 2, 3, 5, 5, 5, 3, 4, 1, 3, 4]") {
        initial = std::vector<int>({1, 1, 5, 1, 1, 4, 5, 3, 1, 3, 2, 2, 1, 4});
        final = std::vector<int>({4, 3, 1, 4, 2, 3, 5, 5, 5, 3, 4, 1, 3, 4});
    }

    hanoi(initial, final, pegs);
    auto hs = hanoi_simulator(initial, num_pegs);
    for (auto const& i : moves) {
        hs.move(i.first, i.second);
    }

    CHECK(std::vector<int>(hs) == final);

    moves.clear();
}

TEST_CASE("6 Pegs.") {
    auto num_pegs = 6;
    auto initial = std::vector<int>();
    auto final = std::vector<int>();
    auto pegs = std::set<int>({1, 2, 3, 4, 5, 6});

    SUBCASE("[1, 1, 1, 1, 1, 1] -> [6, 6, 6, 6, 6, 6, 6]") {
        initial = std::vector<int>({1, 1, 1, 1, 1, 1});
        final = std::vector<int>({6, 6, 6, 6, 6, 6});
    }

    SUBCASE("[6, 6, 5, 4, 5, 6, 4, 3, 1, 2, 3, 4, 6, 2, 4, 5, 1, 3, 5] -> [4, 6, 1, 4, 6, 3, 5, 6, 5, 3, 4, 1, 3, 4, 4, 6, 6, 1, 6]") {
        initial = std::vector<int>({6, 6, 5, 4, 5, 6, 4, 3, 1, 2, 3, 4, 6, 2, 4, 5, 1, 3, 5});
        final = std::vector<int>({4, 6, 1, 4, 6, 3, 5, 6, 5, 3, 4, 1, 3, 4, 4, 6, 6, 1, 6});
    }

    hanoi(initial, final, pegs);
    auto hs = hanoi_simulator(initial, num_pegs);
    for (auto const& i : moves) {
        hs.move(i.first, i.second);
    }

    CHECK(std::vector<int>(hs) == final);

    moves.clear();
}