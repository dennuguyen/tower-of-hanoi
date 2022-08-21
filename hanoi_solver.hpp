#pragma once

#include <cmath>
#include <concepts>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> moves;

auto hanoi(int num_discs, int disc, int from, int to, int free) {
    if (num_discs == 0) {
        return;
    }
    hanoi(num_discs - 1, disc, from, free, to);
    moves.emplace_back(std::make_pair(from, to));
    hanoi(num_discs - 1, disc, free, to, from);
}

auto reves(int num_discs, int from, int to, int free1, int free2) {
    int partition_disc = num_discs + 1 - std::round(std::sqrt(2 * num_discs + 1));
    if (partition_disc == 0) {
        moves.emplace_back(std::make_pair(from, to));
        return;
    }
    reves(partition_disc, from, free1, to, free2);
    hanoi(num_discs - partition_disc, partition_disc, from, to, free2);
    reves(partition_disc, free1, to, from, free2);
}
