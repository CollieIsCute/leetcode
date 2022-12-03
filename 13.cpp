#include <array>
#include <string>
using namespace std;

constexpr static auto init_value() {
	array<int, 'Z' + 1> value{};
	value['I'] = 1;
	value['V'] = 5;
	value['X'] = 10;
	value['L'] = 50;
	value['C'] = 100;
	value['D'] = 500;
	value['M'] = 1000;
	return value;
}

class Solution {
	const static array<int, 'Z' + 1> value;

public:
	int romanToInt(string s) {
		int ret = value[s[s.size() - 1]];
		for(int i = s.size() - 2; i >= 0; i--) {
			if(value[s[i]] < value[s[i + 1]])
				ret -= value[s[i]];
			else
				ret += value[s[i]];
			cout << "ret is: " << ret << endl;
		}
		return ret;
	}
};

constexpr array<int, 'Z' + 1> Solution::value = init_value();