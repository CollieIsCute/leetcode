#include <string>
#include <vector>
using namespace std;
using Big_num = long long;

Big_num calculate(const Big_num& operand1, const Big_num& operand2,
				  const string& op) {
	if(op == "+")
		return operand1 + operand2;
	else if(op == "-")
		return operand1 - operand2;
	else if(op == "*")
		return operand1 * operand2;
	else
		return operand1 / operand2;
}

class Solution {
	vector<Big_num> stk;

public:
	int evalRPN(vector<string>& tokens) {
		for(Big_num i = 0; i < tokens.size(); i++) {
			if(isdigit(tokens[i][0]) || isdigit(tokens[i][1]))
				stk.emplace_back(stoi(tokens[i]));
			else {
				Big_num op1 = stk[stk.size() - 2], op2 = stk[stk.size() - 1];
				stk.pop_back();
				stk.pop_back();
				Big_num temp_ans = calculate(op1, op2, tokens[i]);
				stk.push_back(temp_ans);
			}
		}
		return (int)stk.back();
	}
};
