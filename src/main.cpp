#include <iostream>
#include "util.hpp"
#include "days/day01.hpp"

int main() {
	const auto input = util::readString("../input/day01.txt");
	const auto trimInput = util::trimRight(input);

	const auto parsedInput = parse(trimInput);
	const i32 answer1 = part1(parsedInput);
	const i32 answer2 = part2(parsedInput);

	std::cout << "Answer 1: " << answer1 << '\n';
	std::cout << "Answer 2: " << answer2 << '\n';

	return 0;
}
