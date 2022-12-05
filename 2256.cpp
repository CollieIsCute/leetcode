#include <numeric>
#include <vector>
using namespace std;
using big_type = long long;
int abs_sub(big_type a, big_type b) {
	return a > b ? a - b : b - a;
}

class Solution {
public:
	int minimumAverageDifference(vector<int>& nums) {
		vector<big_type> all_sum(nums.size(), 0), avg(nums.size(), 0), nums_;
		for(const auto& n : nums)
			nums_.push_back(n);
		partial_sum(nums_.begin(), nums_.end(), all_sum.begin());
		for(int i = 0; i < all_sum.size(); i++) {
			int avg1 = all_sum[i] / (i + 1);
			int avg2 = i == all_sum.size() - 1 ? 0
											   : (all_sum.back() - all_sum[i])
													 / (all_sum.size() - i - 1);
			avg[i] = abs_sub(avg1, avg2);
		}
		int ret = 0;
		for(int i = 0; i < avg.size(); i++)
			ret = avg[ret] > avg[i] ? i : ret;
		return ret;
	}
};