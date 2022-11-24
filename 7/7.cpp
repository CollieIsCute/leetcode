#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		string rev = to_string(x);
		auto start_iter = rev.begin() + (x < 0 ? 1 : 0);
		std::reverse(start_iter, rev.end());
		long long ret = std::stoll(rev);
		ret = (ret > 2147483647 or ret < -2147483648) ? 0 : ret;
		return ret;
	}
};
