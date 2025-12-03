#include "day2.h"
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <vector>

namespace adventofcode
{
Day2::Day2() : DaySolver(2) {
    // Data for tests
    test_data =
        R"(11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124)";
    test_results = { 1227775554, 4174379265 };
}

std::vector<std::string> splitByComma(const std::string& s) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, ',')) {
        result.push_back(item);
    }
    return result;
}

std::vector<std::string> splitByDash(const std::string& string) {
    std::stringstream ss(string);
    std::vector<std::string> result;
    std::string temp;
    while (std::getline(ss, temp, '-')) {
        result.emplace_back(temp);
    }
    return result;
}
ResultType Day2::solvePart1() {
    bool test = false;
    bool debug = true;
    long result;
    std::string in_data;
    if (test) {
        in_data = test_data;
    } else {
        in_data = input_data;
    }
    auto data_lines = splitByComma(in_data);
    for (const std::string& data : data_lines) {
        auto temp = splitByDash(data);
        if (debug) {
            std::cout << "[" << temp.at(0) << ", " << temp.at(1) << "]" << "\n";
        }
        long part1_i = std::stol(temp.at(0));
        long part2_i = std::stol(temp.at(1));

        for (long i = part1_i; i < part2_i + 1; i++) {
            std::string tmpStr = std::to_string(i);
            int sizeOfStr = tmpStr.size();
            if (sizeOfStr % 2 == 0) {
                auto half = sizeOfStr / 2;
                std::string part1 = tmpStr.substr(0, half);
                std::string part2 = tmpStr.substr(half, sizeOfStr);

                if (std::stoi(part1) == std::stoi(part2)) {
                    result += i;
                }
            }
        }
    }
    return result;
}

ResultType Day2::solvePart2() {
    bool test = false;
    bool debug = true;
    long result = 0;
    std::string in_data;
    if (test) {
        in_data = test_data;
    } else {
        in_data = input_data;
    }
    auto data_lines = splitByComma(in_data);
    for (const auto& data : data_lines) {
        auto temp = splitByDash(data);
        if (debug) {
            std::cout << "[" << temp.at(0) << ", " << temp.at(1) << "]" << "\n";
        }
        long part1_i = std::stol(temp.at(0));
        long part2_i = std::stol(temp.at(1));

        for (long i = part1_i; i < part2_i + 1; i++) {
            std::string tmpStr = std::to_string(i);

            if ((tmpStr + tmpStr).substr(1, 2 * tmpStr.size() - 2).find(tmpStr) != std::string::npos) {
                result += i;
            }

            // Leaving the below for my own membrance sake lol

            // for (auto len = 0; len < tmpStr.size() / 2; len++) {
            //     std::string searchPattern = tmpStr.substr(0, len);
            //     std::regex regSearch("^(" + searchPattern + ")+$");

            // if (std::regex_match(tmpStr, regSearch)) {
            //     result += i;
            // }
            // auto half = sizeOfStr / 2;
            // std::string firstHalf = tmpStr.substr(0, half);
            //
            // if (j % std::stol(firstHalf.substr(0, j)) == 0) {
            //     result += i;
            //     std::cout << "adding " << i << "\n"; // never enters!!!!
            // }
            // }
            // if (sizeOfStr % 2 == 0) {
            //     if (std::stoi(tmpStr.substr(0, 1)) % i = 0) {
            //     }
            //     for (int i = 0; i < sizeOfStr; i++) {
            //     }
            //     std::string part2 = tmpStr.substr(half, sizeOfStr);
            //
            //     if (std::stoi(part1) == std::stoi(part2)) {
            //         result += i;
            //     }
            // } else { // if not sizeOfStr % 2 != 0 then number needs to all be the same to count no stupid :(
            //     if (tmpStr.substr(0, sizeOfStr / 2 + 1) == tmpStr.substr(sizeOfStr / 2, sizeOfStr)) {
            //         result += i;
            //     }
            // }
        }
    }
    return result;
}
} // namespace adventofcode
