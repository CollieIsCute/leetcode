class Solution {
 public:
  int numberOfChild(int n, int k) {
    auto tmp = k % (2 * n - 2);
    if (tmp >= n) {
      return n - (tmp - n) - 2;
    }
    return tmp;
  }
};
