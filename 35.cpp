#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		long long hi = nums.size() - 1, lo = 0, mid = (hi + lo) / 2;
		for(; lo<hi; mid = (hi + lo) / 2){
			if(nums[mid] >= target)
				hi = mid;
			else
				lo = mid+1;
		}
		if(mid == nums.size()-1 && nums[mid] < target)
			return mid + 1;
		return mid;
	}
};