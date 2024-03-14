#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string removeDuplicates(string s) {
    string tmp_stack;
    while (!s.empty()) {
      if (tmp_stack.empty() || tmp_stack.back() != s.back()) {
        tmp_stack.push_back(move(s.back()));
        s.pop_back();
      } else {
        tmp_stack.pop_back();
        s.pop_back();
      }
    }
    while (!tmp_stack.empty()) {
      s.push_back(move(tmp_stack.back()));
      tmp_stack.pop_back();
    }
    return s;
  }
};