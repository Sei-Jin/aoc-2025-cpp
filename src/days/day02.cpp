/// @file
/// @brief --- Day 2: Gift Shop ---

#include <regex>
#include <string>
#include <vector>

#include "days/day02.hpp"
#include "util.hpp"

std::vector<Range> parse(const std::string& input) {
	auto output = std::vector<Range>();

	const auto ranges = util::split(input, ',');
	for (const auto& range : ranges) {
		const auto pair = util::split(range, '-');
		const auto& lower = std::stoll(pair[0]);
		const auto& upper = std::stoll(pair[1]);
		output.push_back(Range(lower, upper));
	}

	return output;
}

i64 invalidIds(const std::vector<Range>& input, const std::regex& pattern) {
	i64 sum = 0;
	for (const auto v : input) {
		for (i64 i = v.lower; i <= v.upper; i++) {
			if (std::regex_match(std::to_string(i), pattern)) {
				sum += i;
			}
		}
	}
	return sum;
}

i64 part1(const std::vector<Range>& input) {
	const auto pattern = std::regex("^(\\d+)\\1$");
	return invalidIds(input, pattern);
}

i64 part2(const std::vector<Range>& input) {
	return invalidIds(input, std::regex("^(\\d+)\\1+$"));
}