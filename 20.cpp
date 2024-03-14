#include <stack>
using namespace std;

class Solution {
 public:
  bool isValid(const string& s) {
    stack<char> stk;
    for (const auto& ch : s) {
      if (ch == ')' && !stk.empty() && stk.top() == '(')
        stk.pop();
      else if (ch == ']' && !stk.empty() && stk.top() == '[')
        stk.pop();
      else if (ch == '}' && !stk.empty() && stk.top() == '{')
        stk.pop();
      else
        stk.push(ch);
    }
    return stk.empty();
  }
};