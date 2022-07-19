#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret(1, vector<int>(1, 1));	// init to [[1]]
		for(int i = 1; i < numRows; i++) {
			vector<int> now;
			for(int index = -1; index < (int)ret[i - 1].size(); index++)
				now.push_back(my_pascal_add(ret[i - 1], index));
			ret.push_back(now);
		}
		return ret;
	}

	int my_pascal_add(const vector<int>& prev, int index) {
		if(index < 0)
			return prev[index + 1];
		if(index + 1 == prev.size())
			return prev[index];
		return prev[index] + prev[index + 1];
	}
};