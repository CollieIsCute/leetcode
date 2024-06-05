class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    const auto NumsSize = nums.size();
    nums.resize(NumsSize + 1, -1);
    for (auto i = 0; i < NumsSize; i++) {
      while (nums[i] != i && nums[i] != -1) {
        std::swap(nums[i], nums[nums[i]]);
      }
    }
    for (auto i = 0; i < nums.size(); i++) {
      if (nums[i] != i) return i;
    }
    return nums.size();
  }
};
