void remove_factor(int& target, int factor) {
  for (; target && target == (target / factor) * factor; target /= factor);
}

class Solution {
 public:
  bool isUgly(int n) {
    remove_factor(n, 2);
    remove_factor(n, 3);
    remove_factor(n, 5);
    return n == 1;
  }
};