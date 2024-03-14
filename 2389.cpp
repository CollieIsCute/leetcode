#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int find_index(const vector<int>& v, const int target) {
  return upper_bound(v.begin(), v.end(), target) - v.begin();
}

class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, const vector<int>& queries) {
    sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
    vector<int> dp(nums.size()), ans(queries.size());
    partial_sum(nums.begin(), nums.end(), dp.begin());
    for (int i = 0; i < ans.size(); i++) ans[i] = find_index(dp, queries[i]);
    return ans;
  }
};