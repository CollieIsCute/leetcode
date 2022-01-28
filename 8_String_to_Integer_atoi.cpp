#include <string>
#include <sstream>

class Solution {
public:
    int myAtoi(string s) {
		std::stringstream ss(s);
		ss >> std::ws;
		int ret = 0;
		ss >> ret;
		return ret;
	}
};