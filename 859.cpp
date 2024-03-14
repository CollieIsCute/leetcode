#include <inttypes.h>

#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

auto has_dup = [](const string& s) -> bool {
  unordered_set<char> dictionary;
  for (const char& c : s)
    if (dictionary.find(c) != dictionary.end())
      return true;
    else
      dictionary.insert(c);
  return false;
};

class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;
    if (s == goal && has_dup(s)) return true;
    vector<int> diff;
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] != goal[i]) diff.push_back(i);
    }
    if (diff.size() != 2) return false;
    return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
  }
};
