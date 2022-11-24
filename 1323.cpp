#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
	int maximum69Number(int num) {
		stringstream buf;
		buf << num;
		string checker = buf.str();
		for(auto& ch : checker)
			if(ch == '6') {
				ch = '9';
				break;
			}
		return stoi(checker);
	}
};