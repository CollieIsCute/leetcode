class Solution {
 public:
  int valueAfterKSeconds(int n, int k) {
    vector<int> v(n, 1);
    for (auto cnt = 0; cnt < k; cnt++) {
      for (auto i = 1; i < n; i++) {
        v[i] += v[i - 1];
        v[i] %= 1000000007;
      }
    }
    return v.back();
  }
};
