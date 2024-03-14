#include <vector>
using namespace std;
class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    bool is_increasing = true;
    bool is_decreasing = true;
    for (int i = 0; i < nums.size() - 1 && (is_increasing || is_decreasing);
         i++) {
      int dist = nums[i] - nums[i + 1];
      is_increasing &= (dist <= 0);
      is_decreasing &= (dist >= 0);
    }
    return is_increasing || is_decreasing;
  }
};