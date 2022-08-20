#pragma once

#include <cmath>
#include <tuple>
#include <utility>
#include <vector>
#include <iostream>

auto hanoi(std::vector<int> initial, std::vector<int> final, int num_pegs) -> std::vector<std::pair<int, int>> {
}

auto hanoi_type_1(int num_discs, std::vector<int> state, int final_dst) -> std::vector<std::tuple<int, int, int>> {
    std::vector<std::tuple<int, int, int>> moves;
    int curr_dst = final_dst;
    int num_moves = std::pow(2, num_discs) - 1;

    for (int disc = num_discs; disc > 0; disc--) {
        if (state[disc] == curr_dst) {
            num_moves = num_moves - std::pow(2, disc - 1);
        } else {
            moves.emplace_back(std::make_tuple(disc, state[disc], curr_dst));
            curr_dst = 3 - state[disc] - final_dst;
        }
    }

    for (auto const& [m, f, t] : moves) {
        std::cout << "Moving " << std::to_string(m) << " from " << std::to_string(f) << " to " << std::to_string(t) << std::endl;
    }

    return moves;
}