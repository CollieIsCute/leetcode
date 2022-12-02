#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool closeStrings(string word1, string word2) {
		map<char, int> m1, m2;
		set<char> s1, s2;
		vector<int> occ1, occ2;
		for(const char c : word1) {
			++m1[c];
			s1.insert(c);
		}

		for(const char c : word2) {
			++m2[c];
			s2.insert(c);
		}
		if(s1 != s2) // check if they use the same alphabet set.
			return false;
		for(const auto elem : m1)
			occ1.push_back(elem.second);
		for(const auto elem : m2)
			occ2.push_back(elem.second);
		sort(occ1.begin(), occ1.end()); 
		sort(occ2.begin(), occ2.end());
		for(int i = 0; i < occ1.size(); i++) // check occurence
			if(occ1[i] != occ2[i])
				return false;
		return true;
	}
};