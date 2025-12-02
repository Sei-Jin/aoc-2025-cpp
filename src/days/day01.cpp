/// @file
/// @brief --- Day 1: Secret Entrance ---
///
/// https://adventofcode.com/2025/day/1
#include <iostream>
#include <vector>

#include "days/day01.hpp"
#include "util.hpp"

using i32 = int32_t;

std::vector<i32> parse(const std::string& input) {
	auto output = std::vector<i32>();

	const auto lines = util::split(input, '\n');
	for (auto line : lines) {
		const char direction = line[0];
		auto rawValue = line.substr(1);
		i32 value = std::stoi(rawValue);

		if (direction == 'R') {
			output.push_back(value);
		} else {
			output.push_back(-value);
		}
	}

	return output;
}

i32 part1(const std::vector<i32>& input) {
	i32 points = 0;

	i32 dial = 50;
	for (const auto v : input) {
		dial += v;
		dial = dial % 100;
		if (dial < 0) {
			dial += 100;
		} else if (dial == 0) {
			points += 1;
		}
	}

	return points;
}

i32 part2(const std::vector<i32>& input) {
	i32 points = 0;

	i32 dial = 50;
	for (const auto shift : input) {
		if (shift < 0) {
			for (i32 i = shift; i < 0; i++) {
				dial--;
				if (dial < 0) {
					dial = 99;
				} else if (dial == 0) {
					points++;
				}
			}
		} else {
			for (i32 i = 0; i < shift; i++) {
				dial++;
				if (dial > 99) {
					dial = 0;
				}
				if (dial == 0) {
					points++;
				}
			}
		}
	}

	return points;
}