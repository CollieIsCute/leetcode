#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
		std::reverse(s.begin(), s.end());
    }
};
