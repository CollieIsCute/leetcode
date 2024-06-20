class Solution {
 public:
  int commonFactors(int a, int b) {
    auto GCD = std::gcd(a, b);
    auto cnt = 0;
    for (auto i = 1; i <= GCD; i++) {
      if (GCD % i) continue;
      ++cnt;
    }
    return cnt;
  }
};
