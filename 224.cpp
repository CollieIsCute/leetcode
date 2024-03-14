#include <stack>
#include <string>
using namespace std;

// after parsing, put `it` represent the last digit of num
int parse_num(int& num_head, const string& s) {
  int cnt = 0, sign = (num_head > 0 && s[num_head - 1] == '-') ? -1 : 1;
  for (; isdigit(s[num_head + cnt]); cnt++)
    ;
  int n = stoi(s.substr(num_head, cnt));
  num_head += (cnt - 1);
  return n * sign;
}

class Solution {
 public:
  int calculate(string s) {
    s.erase(remove_if(s.begin(), s.end(),
                      [](unsigned char ch) { return std::isspace(ch); }),
            s.end());
    stack<int> sign_stack{};
    int ret = 0, cur_sign = 1;
    for (auto it = 0; it < s.size(); it++)
      if (isdigit(s[it]))
        ret += parse_num(it, s) * cur_sign;
      else if (s[it] == '(') {
        if (it > 0 && s[it - 1] == '-')
          sign_stack.push(-1);
        else
          sign_stack.push(1);
        cur_sign *= sign_stack.top();
      } else if (s[it] == ')') {
        cur_sign /= sign_stack.top();
        sign_stack.pop();
      }
    return ret;
  }
};