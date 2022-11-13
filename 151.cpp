#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		stringstream buf(s);
		string word, all;
		while(buf >> word >> ws)
			all =  word + (all!=""?" ":"") + all;
		return all;
	}
};