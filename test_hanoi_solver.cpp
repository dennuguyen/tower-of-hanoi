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

// TEST_SUITE("4 Pegs.") {
//     TEST_CASE("[1, 1, 1, 1, 1] -> [3, 3, 3, 3, 3]") {
//         auto num_pegs = 4;
//         auto initial = std::vector<int>({1, 1, 1, 1, 1});
//         auto final = std::vector<int>({3, 3, 3, 3, 3});

//         reves(initial.size(), 1, 3, 2, 4);
//         auto hs = hanoi_simulator(initial, num_pegs);
//         for (auto const& i : moves) {
//             hs.move(i.first, i.second);
//         }

//         std::cout << hs << std::endl;
//         std::cout << final << std::endl;

//         CHECK(std::vector<int>(hs) == final);

//         moves.clear();
//     }

//     TEST_CASE("[1, 1, 1, 1, 1, 1, 1] -> [2, 2, 2, 2, 2, 2, 2]") {
//         auto num_pegs = 4;
//         auto initial = std::vector<int>({1, 1, 1, 1, 1, 1, 1});
//         auto final = std::vector<int>({2, 2, 2, 2, 2, 2, 2});

//         reves(initial.size(), 1, 2, 3, 4);
//         auto hs = hanoi_simulator(initial, num_pegs);
//         for (auto const& i : moves) {
//             hs.move(i.first, i.second);
//         }

//         std::cout << hs << std::endl;
//         std::cout << final << std::endl;

//         CHECK(std::vector<int>(hs) == final);

//         moves.clear();
//     }
// }