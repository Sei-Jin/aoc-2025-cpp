#include <fstream>
#include <string>
#include <vector>

using i32 = int32_t;
using u64 = uint64_t;

namespace util {
	std::string readString(const std::string& filePath) {
		std::string content;
		std::ifstream fileStream(filePath, std::ios::in);
		std::string line;

		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			content.append(line + '\n');
		}

		fileStream.close();
		return content;
	}

	std::string trimRight(const std::string& s) {
		const u64 last = s.find_last_not_of("\n\t\v\f\r ");
		return s.substr(0, last + 1);
	}

	std::vector<std::string> split(const std::string& s, const char d) {
		auto output = std::vector<std::string>();
		i32 left = 0;
		for (i32 right = 0; right < s.length(); right++) {
			if (s[right] == d && left != right) {
				output.push_back(s.substr(left, right - left));
				left = right + 1;
			}
		}
		output.push_back(s.substr(left));
		return output;
	}
}
