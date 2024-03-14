#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    size_t reach_limit = 0;
    for (size_t step = 0; step <= min(reach_limit, nums.size() - 1); step++)
      reach_limit = max(reach_limit, step + nums[step]);
    return reach_limit >= nums.size() - 1;
  }
};