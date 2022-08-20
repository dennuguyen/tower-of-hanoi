#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hanoi_simulator.hpp"
#include "hanoi_solver.hpp"

TEST_CASE("Hanoi with 3 pegs and 4 discs.") {
    auto num_pegs = 3;

    SUBCASE("") {
        auto initial = std::vector<int>({1, 1, 1, 1});
        auto final = std::vector<int>({3, 3, 3, 3});

        auto moves = hanoi(initial, final, num_pegs);
        auto hs = hanoi_simulator(initial, num_pegs);
        for (auto const& i : moves) {
            hs.move(i.first, i.second);
        }

        CHECK(std::vector<int>(hs) == final);
    }

    SUBCASE("") {
        auto initial = std::vector<int>({1, 1, 1, 1});
        auto final = std::vector<int>({3, 3, 3, 2});

        auto moves = hanoi(initial, final, num_pegs);
        auto hs = hanoi_simulator(initial, num_pegs);
        for (auto const& i : moves) {
            hs.move(i.first, i.second);
        }

        CHECK(std::vector<int>(hs) == final);
    }
}

TEST_CASE("Hanoi with 3 pegs and 5 discs.") {
    auto num_pegs = 3;
    auto initial = std::vector<int>({1, 1, 1, 1, 1});

    SUBCASE("") {
        auto final = std::vector<int>({3, 3, 1, 2, 3});

        auto moves = hanoi(initial, final, num_pegs);
        auto hs = hanoi_simulator(initial, num_pegs);
        for (auto const& i : moves) {
            hs.move(i.first, i.second);
        }

        CHECK(std::vector<int>(hs) == final);
    }
}