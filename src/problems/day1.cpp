#include "day1.h"
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <string>

namespace adventofcode
{
Day1::Day1() : DaySolver(1) {
    // Data for tests
    test_data = R"(L68 L30 R48 L5 R60 L55 L1 L99 R14 L82)";
    test_results = { 3, 6 };
}

ResultType Day1::solvePart1() {
    int combination = 50;
    auto debug = false;
    if (debug) {
        std::cout << "start: " << combination << "\n";
    }

    int result = 0;
    // Separating into lines for each input
    // auto data_lines = test_data | std::views::split(' ');
    auto data_lines = input_data | std::views::split('\n');
    for (const auto& num : data_lines) {
        std::string temp(num.begin(), num.end());
        int value = std::stoi(temp.substr(1));

        if (num[0] == 'L') {
            combination -= value;
            if (debug) {
                std::cout << "Rotated L";
            }
        } else {
            combination += value;
            if (debug) {
                std::cout << "Rotated R";
            }
        }
        if (combination < 0) {
            combination %= 100;
        } else if (combination > 99) {
            combination %= 100;
        }
        if (debug) {
            std::cout << value << " to " << combination << "\n";
        }
        if (combination == 0) {
            result += 1;
        }
    }

    return result;
}

ResultType Day1::solvePart2() {
    int result = 0;
    int combination = 50;
    auto debug = false;

    if (debug) {
        std::cout << "start: " << combination << "\n";
    }
    // auto data_lines = test_data | std::views::split(' ');
    auto data_lines = input_data | std::views::split('\n');

    for (const auto& num : data_lines) {
        std::string temp(num.begin(), num.end());
        int value = std::stoi(temp.substr(1));
        std::string rotatedStr = "";
        std::string zeroval = "";

        if (num[0] == 'L') {
            int prev_comb = combination;
            result += (value / 100);
            value %= 100;
            combination += (100 - value);
            if (combination <= 100 && prev_comb != 0) {
                result++;
            }
            combination = (combination % 100);
        } else if (num[0] == 'R') {
            combination += value;
            if (combination >= 100) {
                result += (combination / 100);
                combination %= 100;
            }
        }
        if (debug) {
            std::cout << "[Rotated " << temp << " to " << combination << "]" << zeroval << "\n";
        }
        assert(combination >= 0);
        assert(combination <= 99);
    }
    return result;
}

} // namespace adventofcode
