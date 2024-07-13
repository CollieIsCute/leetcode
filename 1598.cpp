class Solution {
 public:
  int minOperations(vector<string>& logs) {
    auto cnt = 0;
    for (const auto& log : logs) {
      if (log == "../") {
        if (cnt > 0) --cnt;
      } else if (log == "./") {
      } else {
        ++cnt;
      }
    }
    return cnt;
  }
};
