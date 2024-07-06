class Solution {
 public:
  int passThePillow(int n, int time) {
    auto ans = (time) % (2 * (n - 1));
    if (ans < n)
      return ans + 1;
    else
      return 2 * n - ans - 1;
  }
};
