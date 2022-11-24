#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	using Property = vector<int>;
	using Properties = vector<Property>;
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		int ret = 0;
		sort(properties.begin(), properties.end(), Solution::compare);
		int max = INT_MIN;
		for(const auto& p : properties) {
			if(max > p[1])
				ret++;
			else if(max < p[1])
				max = p[1];
		}
		return ret;
	}
	static bool compare(Property& a, Property& b) {
		if(a[0] == b[0])
			return a[1] < b[1];
		else
			return a[0] > b[0];
	}
};
