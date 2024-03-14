#include <string>
using namespace std;

bool not_good(char ch1, char ch2) {
  constexpr int distance = 'a' - 'A';
  return (ch1 == ch2 + distance || ch1 == ch2 - distance);
}

class Solution {
 public:
  string makeGood(string s) {
    string ret = {};
    int cur = 0;
    while (cur < s.size()) {
      if (!ret.empty() && not_good(ret.back(), s[cur]))
        ret.pop_back();
      else
        ret.push_back(s[cur]);
      ++cur;
    }
    return ret;
  }
};