#pragma once

#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> moves;

auto hanoi(int num_discs, int disc, int from, int free, int to) {
    if (num_discs == 0) {
        return;
    }
    hanoi(num_discs - 1, disc, from, to, free);
    moves.emplace_back(std::make_pair(from, to));
    hanoi(num_discs - 1, disc, free, from, to);
}

auto reves(int num_discs, int from, int free1, int to, int free2) {
    int partition_disc = num_discs + 1 - std::round(std::sqrt(2 * num_discs + 1));
    if (partition_disc == 0) {
        moves.emplace_back(std::make_pair(from, to));
        return;
    }
    reves(partition_disc, from, to, free1, free2);
    hanoi(num_discs - partition_disc, partition_disc, from, free2, to);
    reves(partition_disc, free1, from, to, free2);
}
