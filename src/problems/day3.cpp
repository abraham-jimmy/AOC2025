#include "day3.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace adventofcode
{
Day3::Day3() : DaySolver(3) {
    // Data for tests
    test_data = R"(987654321111111
811111111111119
234234234234278
818181911112111)";
    test_results = { 357, 3121910778619 };
}

std::vector<std::string> splitByNewLine(const std::string& s) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, '\n')) {
        result.push_back(item);
    }
    return result;
}
ResultType Day3::solvePart1() {
    bool test = false;
    bool debug = false;
    int result = 0;
    int max_sum;
    // int temp;
    std::string in_data;
    if (test) {
        in_data = test_data;
    } else {
        in_data = input_data;
    }

    auto data_lines = splitByNewLine(in_data);
    for (const std::string& line : data_lines) {
        // auto str_line = line);
        if (debug) {
            std::cout << "[" << line << "]" << "\n";
        }
        int length = line.size();
        max_sum = 0;
        // int num_first;
        // int num_second;
        // int iter_num;
        // std::cout << line.size() << std::endl;
        for (int i = 0; i < length; i++) {
            int current_max = 0;
            if (debug) {
                // std::cout << line[i] << "\n";
            }
            for (int j = 1; j <= line.size() - i - 1; j++) {
                // std::cout << "line[" << i << "]= " << (line[i] - '0') * 10 << ", line[" << i + j << "] = " << (line[i + j] - '0')
                // << "\n";
                current_max = (line[i] - '0') * 10 + (line[i + j] - '0');
                // if (num == '9') {
                //     num_first = num * 10 + ;
                //     num = iter_num;
                // }
                // iter_num++;
                if (current_max > max_sum) {
                    max_sum = current_max;
                    // std::cout << "current_max = " << current_max << " max_sum = " << max_sum << " result = " << result << "\n";
                }
            }
        }
        result += max_sum;
        // std::cout << " result = " << result << "\n";
    }
    return result;
}

ResultType Day3::solvePart2() {
    bool test = false;
    bool debug = false;
    long long result = 0;
    long long max_val;
    // int temp;
    std::string in_data;
    if (test) {
        in_data = test_data;
    } else {
        in_data = input_data;
    }

    auto data_lines = splitByNewLine(in_data);
    for (const std::string& line : data_lines) {
        if (debug) {
            // std::cout << "[" << line << "]" << "\n";
        }
        int length = line.size();
        max_val = 0;
        for (int i = 0; i < length; i++) {
            int current_max = 0;
            // if (debug) {
            //     std::cout << line[i] << "\n";
            // }
            for (int j = 1; j <= line.size() - i - 1; j++) {
                for (int k = 2; k <= line.size() - i - j - 1; k++) {
                    // std::cout << "line[" << i << "]= " << (line[i] - '0') * 10 << ", line[" << i + j
                    //           << "] = " << (line[i + j] - '0') << "\n";
                    std::string temp_str = line;
                    // std::cout << "Before: " << temp_str << "\n";
                    temp_str.erase(temp_str.begin() + k);
                    temp_str.erase(temp_str.begin() + j);
                    temp_str.erase(temp_str.begin() + i);
                    // std::cout << "After: " << temp_str << "\n";
                    long long current = std::stoll(temp_str);
                    if (current > max_val) {
                        max_val = current;
                        if (debug) {
                            std::cout << "current_max = " << current << " max_sum = " << max_val << " result = " << result << "\n";
                        }
                    }
                }
            }
        }
        result += max_val;
        if (debug) {
            std::cout << " result = " << result << "\n";
        }
    }
    return result;
}

} // namespace adventofcode
