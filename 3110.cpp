class Solution {
 public:
  int scoreOfString(string s) {
    auto cnt = 0;
    for (auto i = 0; i < s.size() - 1; i++) {
      cnt += abs(s[i] - s[i + 1]);
    }
    return cnt;
  }
};
