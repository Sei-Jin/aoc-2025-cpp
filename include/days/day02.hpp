#pragma once

using i64 = int64_t;

struct Range {
	i64 lower;
	i64 upper;
};

std::vector<Range> parse(const std::string& input);

i64 part1(const std::vector<Range>& input);

i64 part2(const std::vector<Range>& input);