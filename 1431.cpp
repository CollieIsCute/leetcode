#include <vector>
using namespace std;

class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max_candies = candies[0];
		for(const int& n : candies)
			max_candies = max(max_candies, n);
		vector<bool> ret;
		for(const int& n : candies)
			ret.push_back(extraCandies + n >= max_candies);
		return ret;
	}
};
