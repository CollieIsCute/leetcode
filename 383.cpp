#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> rans, mag;
		for(const char& ch : magazine) {
			if(mag.find(ch) != mag.end())
				mag[ch]++;
			else
				mag[ch] = 1;
		}

		for(const char& ch : ransomNote) {
			if(mag.find(ch) == mag.end())
				return false;
			else {
				mag[ch]--;
				if(mag[ch] == 0)
					mag.erase(ch);
			}
		}
		return true;
	}
};
