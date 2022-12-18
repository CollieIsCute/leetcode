#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(const vector<int>& temperatures) {
		vector<int> stk;
		vector<int> ans(temperatures.size());
		for(int i = temperatures.size() - 1; i >= 0; --i) {
			while(!stk.empty() && temperatures[stk.back()] <= temperatures[i])
				stk.pop_back();
			ans[i] = stk.size() ? stk.back() - i : 0;
			stk.push_back(i);
		}
		return ans;
	}
};