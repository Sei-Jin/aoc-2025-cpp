#include <iostream>

#include "util.hpp"
#include "days/day02.hpp"

int main() {
	const auto input = util::readString("../input/day02.txt");
	const auto trimInput = util::trimRight(input);

	const auto parsedInput = parse(trimInput);
	const auto answer1 = part1(parsedInput);
	const auto answer2 = part2(parsedInput);

	std::cout << "Answer 1: " << answer1 << '\n';
	std::cout << "Answer 2: " << answer2 << '\n';

	return 0;
}
