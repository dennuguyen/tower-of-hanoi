#pragma once

#include <algorithm>
#include <concepts>
#include <experimental/iterator>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <std::integral T>
class hanoi_simulator {
   public:
    // Initialise the Hanoi simulator with an initial state.
    // @param initial_state The initial peg state where initial_state[disc] = peg.
    // @param num_pegs Maximum number of pegs.
    // @throw If any discs have an invalid peg value i.e. outside the range [1, num_pegs].
    explicit hanoi_simulator(std::vector<T> const& pegs, T const& num_pegs) : pegs(pegs), num_pegs(num_pegs) {
        std::for_each(pegs.begin(), pegs.end(), [*this](auto const& i) {
            check_peg_range(i);
        });
    }

    // Moves the disc at the from_peg peg to the to peg.
    // @param from_peg The peg to move a disc from.
    // @param to_peg The peg to move a disc to.
    // @return True if the disc is moved and false otherwise.
    // @throw If no disc exists at the from_peg peg.
    // @throw If the move is illegal.
    // @throw If from_peg or to_peg is outside the range [1, num_pegs].
    auto move(T from_peg, T to_peg) -> bool {
        check_peg_range(from_peg);
        check_peg_range(to_peg);

        if (from_peg == to_peg) {
            return false;
        }

        // Find top disc at from_peg.
        auto from_disc = std::find(pegs.rbegin(), pegs.rend(), from_peg);
        if (from_disc == pegs.rend()) {
            throw std::logic_error("No disc at peg to move from.");
        }

        // Find top disc at to_peg.
        auto to_disc = std::find(pegs.rbegin(), pegs.rend(), to_peg);

        // Moves are only valid if disc to be moved aka from_disc is smaller than to_disc.
        if (from_disc > to_disc) {
            throw std::logic_error("Larger disc cannot be moved on top of a smaller disc.");
        }

        // Move disc.
        *from_disc = to_peg;

        return true;
    }

    explicit operator std::vector<T>() const noexcept {
        return std::vector<T>(pegs.begin(), pegs.end());
    }

    friend auto operator<<(std::ostream& os, hanoi_simulator const& hs) noexcept -> std::ostream& {
        os << "[";
        std::copy(hs.pegs.begin(), hs.pegs.end(), std::experimental::make_ostream_joiner(os, ", "));
        os << "]";
        return os;
    }

   private:
    auto check_peg_range(T peg) const -> void {
        if (peg < 1 || peg > num_pegs) {
            throw std::invalid_argument("Invalid peg, " + std::to_string(peg) + ", found outside the range [1, " + std::to_string(num_pegs) + "].");
        }
    }

    std::vector<T> pegs;
    const T num_pegs;
};