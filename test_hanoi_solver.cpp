#include <experimental/iterator>
#include <iostream>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hanoi_simulator.hpp"
#include "hanoi_solver.hpp"

template <typename T>
auto operator<<(std::ostream& os, std::vector<T> const& v) -> std::ostream& {
    os << "[";
    std::copy(v.begin(), v.end(), std::experimental::make_ostream_joiner(os, ", "));
    os << "]";
    return os;
}

// TEST_SUITE("Hanoi with 3 pegs and 4 discs.") {
// TEST_CASE("[1, 1, 1, 1] -> [3, 3, 3, 3]") {
//     auto num_pegs = 3;
//     auto initial = std::vector<int>({1, 1, 1, 1});
//     auto final = std::vector<int>({3, 3, 3, 3});

//     // hanoi(initial.size(), initial, final, num_pegs);
//     reves(4, 1, 2, 3, 4);
//     auto hs = hanoi_simulator(initial, num_pegs);
//     for (auto const& i : moves) {
//         hs.move(i.first, i.second);
//     }

//     CHECK(std::vector<int>(hs) == final);
// }

// TEST_CASE("[1, 1, 1, 1] -> [3, 3, 3, 2]") {
//     auto num_pegs = 3;
//     auto initial = std::vector<int>({1, 1, 1, 1});
//     auto final = std::vector<int>({3, 3, 3, 2});

//     hanoi(initial.size(), initial, final, num_pegs);
//     auto hs = hanoi_simulator(initial, num_pegs);
//     for (auto const& i : moves) {
//         hs.move(i.first, i.second);
//     }

//     CHECK(std::vector<int>(hs) == final);
// }
// }

// TEST_SUITE("Hanoi with 3 pegs and 5 discs.") {
//     TEST_CASE("[1, 1, 1, 1, 1] -> [3, 3, 1, 2, 3]") {
//         auto num_pegs = 3;
//         auto initial = std::vector<int>({1, 1, 1, 1, 1});
//         auto final = std::vector<int>({3, 3, 1, 2, 3});

//         hanoi(initial.size(), initial, final, num_pegs);
//         auto hs = hanoi_simulator(initial, num_pegs);
//         for (auto const& i : moves) {
//             hs.move(i.first, i.second);
//         }

//         CHECK(std::vector<int>(hs) == final);
//     }
// }

TEST_SUITE("4 Pegs.") {
    TEST_CASE("[1, 1, 1, 1, 1] -> [3, 3, 3, 3, 3]") {
        auto num_pegs = 4;
        auto initial = std::vector<int>({1, 1, 1, 1, 1});
        auto final = std::vector<int>({3, 3, 3, 3, 3});

        reves(initial.size(), 1, 2, 3, 4);
        auto hs = hanoi_simulator(initial, num_pegs);
        for (auto const& i : moves) {
            hs.move(i.first, i.second);
        }

        std::cout << hs << std::endl;
        std::cout << final << std::endl;

        CHECK(std::vector<int>(hs) == final);

        moves.clear();
    }

    TEST_CASE("[1, 1, 1, 1, 1, 1, 1] -> [2, 2, 2, 2, 2, 2, 2]") {
        auto num_pegs = 4;
        auto initial = std::vector<int>({1, 1, 1, 1, 1, 1, 1});
        auto final = std::vector<int>({2, 2, 2, 2, 2, 2, 2});

        reves(initial.size(), 1, 3, 2, 4);
        auto hs = hanoi_simulator(initial, num_pegs);
        for (auto const& i : moves) {
            hs.move(i.first, i.second);
        }

        std::cout << hs << std::endl;
        std::cout << final << std::endl;

        CHECK(std::vector<int>(hs) == final);

        moves.clear();
    }
}