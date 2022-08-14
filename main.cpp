#include "hanoi_simulator.hpp"

int main() {
    auto hs = hanoi_simulator({1, 1, 4}, 3);
    std::cout << hs << std::endl;
    hs.move(1, 2);
}