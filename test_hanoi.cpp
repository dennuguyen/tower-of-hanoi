#include <algorithm>
#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define DOCTEST_VALUE_PARAMETERIZED_DATA(data, data_container)                        \
    static size_t _doctest_subcase_idx = 0;                                           \
    std::for_each(data_container.begin(), data_container.end(), [&](const auto& in) { \
        DOCTEST_SUBCASE((std::string(#data_container "[") +                           \
                         std::to_string(_doctest_subcase_idx++) + "]")                \
                            .c_str()) { data = in; }                                  \
    });                                                                               \
    _doctest_subcase_idx = 0

#include "hanoi.hpp"

auto generate_test_cases(std::vector<int> pegs, std::vector<int> discs) -> std::vector<std::vector<int>> {
}

TEST_CASE("test_hanoi") {
    auto parameterised_pegs = std::vector<int>();
    auto parameterised_discs = std::vector<int>();
    auto pegs = std::vector<int>({3, 4, 5});
    auto discs = std::vector<int>({0, 1, 2, 3, 4, 5, 6});

    DOCTEST_VALUE_PARAMETERIZED_DATA(parameterised_pegs, parameterised_discs, pegs, discs);

    CHECK(hanoi(parameterised_pegs, parameterised_discs), parameterised_discs);
}