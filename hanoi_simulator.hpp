#pragma once

#include <algorithm>
#include <experimental/iterator>
#include <iostream>
#include <vector>

class hanoi_simulator {
   public:
    explicit hanoi_simulator(std::vector<int> initial_state, int num_pegs) : pegs(initial_state), num_pegs(num_pegs) {
    }

    // Moves the disc at the from peg to the to peg.
    // @param from The peg to move a disc from.
    // @param to The peg to move a disc to.
    // @return True if the disc is moved and false otherwise.
    // @throw If no disc exists at the from peg.
    // @throw If the move is illegal.
    auto move(int from, int to) -> bool {
        if (from == to) {
            return false;
        }

        // Find disc at from peg.
        auto from_disc = std::find(pegs.rbegin(), pegs.rend(), from);
        if (from_disc == pegs.rend()) {
            throw std::logic_error("No disc at peg to move from.");
        }

        // Find disc at to peg.
        auto to_disc = std::find(pegs.rbegin(), pegs.rend(), to);

        // Check if move is valid.
        // Moves are only valid if righter discs on top of any lefter discs.
        // Lefter discs can move to a peg if no righter discs occupy it.

        // Move disc.
        pegs[*from_disc] = to;

        return true;
    }

    friend auto operator<<(std::ostream& os, hanoi_simulator const& hs) noexcept -> std::ostream& {
        os << "[";
        std::copy(hs.pegs.begin(), hs.pegs.end(), std::experimental::make_ostream_joiner(os, ", "));
        os << "]";
        return os;
    }

   private:
    std::vector<int> pegs;
    int num_pegs;
};