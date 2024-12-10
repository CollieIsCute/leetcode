#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_map>

class Solution {
  bool validString(std::string_view s, int n) {
    std::unordered_map<std::string_view, int> um;
    for (size_t i = 0; i + n <= s.size(); ++i) {
      auto temp_view = s.substr(i, n);
      if (std::all_of(temp_view.begin(), temp_view.end(),
                      [&](char c) { return c == temp_view.front(); })) {
        um[temp_view]++;
      }
    }
    for (const auto& p : um) {
      if (p.second >= 3) {
        return true;
      }
    }
    return false;
  }

 public:
  int maximumLength(std::string s) {
    int left = 1, right = s.size();
    int result = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (validString(s, mid)) {
        result = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return result;
  }
};
