class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto ret = 0;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ret += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ret;
    }
};
