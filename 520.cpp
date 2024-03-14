#include <string>
using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    int upper_cnt = 0;
    for (const auto& ch : word) upper_cnt += static_cast<bool>(isupper(ch));
    if (!upper_cnt || upper_cnt == word.size()) return true;
    if (isupper(word[0]) && upper_cnt == 1) return true;
    return false;
  }
};