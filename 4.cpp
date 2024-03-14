#include <vector>
using namespace std;
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int total_size = nums1.size() + nums2.size();
    const int less_median_index =
        (total_size % 2) ? total_size / 2 : total_size / 2 - 1;
    bool there_are_odd_numbers = total_size % 2;
    for (int i = 0; i < less_median_index; i++)
      get_and_pop_biggest(nums1, nums2);
    if (there_are_odd_numbers)
      return (double)get_and_pop_biggest(nums1, nums2);
    else {
      double a, b;
      a = get_and_pop_biggest(nums1, nums2);
      b = get_and_pop_biggest(nums1, nums2);
      return (a + b) / 2.0;
    }
  }

  int get_and_pop_biggest(vector<int>& nums1, vector<int>& nums2) {
    if (!nums1.empty() || !nums2.empty()) {
      vector<int>& target = get_max(nums1, nums2);
      int ret = target.back();
      target.pop_back();
      return ret;
    } else
      return -1;
  }

  vector<int>& get_max(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() && nums2.empty()) return nums1;
    if (logical_xor(nums1.empty(), nums2.empty()))
      return nums1.empty() ? nums2 : nums1;
    return (nums1.back() > nums2.back()) ? nums1 : nums2;
  }

  inline bool logical_xor(bool a, bool b) { return a ? !b : b; }
};