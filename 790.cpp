// see
// https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116581/detail-and-explanation-of-o-n-solution-why-dp-n-2-d-n-1-dp-n-3/?orderBy=hot
// for a drawing explaination

#include <vector>
using namespace std;

using BigNum = int;

constexpr BigNum auto_mod(BigNum&& tar) { return tar % 1000000007; }

constexpr BigNum auto_mod(BigNum& tar) {
  tar %= 1000000007;
  return tar;
}

constexpr auto make_list() {
  auto dp = {1, 1, 2, 5};
  constexpr int SOLUTION_RANGE = 1001;
  for (int i = 4; i < SOLUTION_RANGE; i++) {
    int temp = auto_mod(dp[i - 1] * 2) + auto_mod(dp[i - 3]);
    dp.push_back(auto_mod(temp));
  }
  return dp;
}

class Solution {
  constexpr vector<int> dp = make_list();

 public:
  int numTilings(int n) { return dp[n]; }
};