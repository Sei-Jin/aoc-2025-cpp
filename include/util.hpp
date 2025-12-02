#pragma once

#include <string>
#include <vector>

namespace util {
	std::string readString(const std::string& filePath);
	std::string trimRight(const std::string& sv);
	std::vector<std::string> split(const std::string& s, char d);
}
