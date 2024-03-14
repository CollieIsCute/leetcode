#include <vector>
using namespace std;

class Solution {
 public:
  int rob(const vector<int>& nums) {
    vector<int> ans(nums);
    for (int i = 1; i < ans.size(); ++i)
      if (i == 1)
        ans[i] = max(ans[i], ans[i - 1]);
      else
        ans[i] = max(ans[i - 1], ans[i - 2] + ans[i]);
    return ans.back();
  }
};