#pragma once

#include <cmath>
#include <concepts>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

template <template <typename> typename Cont, typename T>
auto operator<<(std::ostream& os, Cont<T> const& cont) -> std::ostream& {
    os << "[";
    std::copy(cont.begin(), cont.end(), std::experimental::make_ostream_joiner(os, ", "));
    os << "]";
    return os;
}

std::vector<std::pair<int, int>> moves;

auto hanoi(std::vector<int> from, std::vector<int> to, std::set<int> pegs = {1, 2, 3}) {
    // Base case after placing all discs in their rightful positions.
    if (from.empty()) {
        return;
    }

    // Determine which pegs are free i.e. not from and to pegs.
    auto temp = pegs;
    temp.erase(from.at(0));
    temp.erase(to.at(0));
    auto free = std::vector<int>(from.size() - 1, *temp.begin());

    // Keep exploring subsolutions.
    hanoi({from.begin() + 1, from.end()}, free, pegs);
    moves.emplace_back(std::make_pair(from.at(0), to.at(0)));
    hanoi(free, {to.begin() + 1, to.end()}, pegs);
}

// Classic Tower of Hanoi 3 peg recursive solution.
// auto hanoi(int num_discs, int from, int to, int free) {
//     if (num_discs == 0) {
//         return;
//     }
//     hanoi(num_discs - 1, from, free, to);
//     moves.emplace_back(std::make_pair(from, to));
//     hanoi(num_discs - 1, free, to, from);
// }

// Recursive Frame-Stewart algorithm.
// auto reves(int num_discs, int from, int to, int free1, int free2) {
//     int partition_disc = num_discs + 1 - std::round(std::sqrt(2 * num_discs + 1));
//     if (partition_disc == 0) {
//         moves.emplace_back(std::make_pair(from, to));
//         return;
//     }
//     reves(partition_disc, from, free1, to, free2);
//     hanoi(num_discs - partition_disc, from, to, free2);
//     reves(partition_disc, free1, to, from, free2);
// }
