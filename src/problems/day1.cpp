#include "day1.h"
#include <iostream>

namespace adventofcode
{
Day1::Day1() : DaySolver(1) {
    // Data for tests
    test_data = R"(
                    L68
                    L30
                    R48
                    L5
                    R60
                    L55
                    L1
                    L99
                    R14
                    L82)";
    test_data2 = R"()";
    test_results = { 3, 0 };
}

ResultType Day1::solvePart1() {
    int num = 1;

    for (const auto num : input_data) {
        std::cout << input_data << "\n";
    }
    return 0;
}

ResultType Day1::solvePart2() { return 0; }

} // namespace adventofcode
