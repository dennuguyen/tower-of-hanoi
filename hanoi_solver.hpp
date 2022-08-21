#pragma once

#include <cmath>
#include <concepts>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

template <typename T>
auto operator<<(std::ostream& os, std::vector<T> const& v) -> std::ostream& {
    os << "[";
    std::copy(v.begin(), v.end(), std::experimental::make_ostream_joiner(os, ", "));
    os << "]";
    return os;
}

std::vector<std::pair<int, int>> moves;

auto hanoi(std::vector<int> from, std::vector<int> to) {
    if (from.empty()) {
        // Base case after placing all discs in their rightful positions.
        return;
    } else if (from.at(0) == to.at(0)) {
        // Base case for placing the largest disc at its rightful position.
        hanoi({from.begin() + 1, from.end()}, {to.begin() + 1, to.end()});
    } else {
        // Determine which pegs are free i.e. not from and to pegs.
        auto pegs = std::set<int>({1, 2, 3});
        pegs.erase(from.at(0));
        pegs.erase(to.at(0));
        auto free = std::vector<int>(from.size() - 1, *pegs.begin());

        // Keep exploring subsolutions.
        hanoi({from.begin() + 1, from.end()}, free);
        moves.emplace_back(std::make_pair(from.at(0), to.at(0)));
        hanoi(free, {to.begin() + 1, to.end()});
    }
}

/////////////// EVERYTHING BELOW WORKS FOR REVE'S with 4 PEGS AND N DISCS.

// auto hanoi(int num_discs, int disc, int from, int to, int free) {
//     if (num_discs == 0) {
//         return;
//     }
//     hanoi(num_discs - 1, disc, from, free, to);
//     moves.emplace_back(std::make_pair(from, to));
//     hanoi(num_discs - 1, disc, free, to, from);
// }

// auto reves(int num_discs, int from, int to, int free1, int free2) {
//     int partition_disc = num_discs + 1 - std::round(std::sqrt(2 * num_discs + 1));
//     if (partition_disc == 0) {
//         moves.emplace_back(std::make_pair(from, to));
//         return;
//     }
//     reves(partition_disc, from, free1, to, free2);
//     hanoi(num_discs - partition_disc, partition_disc, from, to, free2);
//     reves(partition_disc, free1, to, from, free2);
// }
