#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ret;
    for (int cnt = 0;; ++cnt) {
      char cur = '0';
      for (const auto& s : strs) {
        if (cnt >= s.size())
          return ret;
        else if (cur != '0' && s[cnt] != cur)
          return ret;
        else if (cur == '0')
          cur = s[cnt];
      }
      ret += cur;
    }
    return ret;
  }
};