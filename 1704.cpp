#include <iostream>
#include <string>
using namespace std;

class Solution {
	const string vowel{"aeiouAEIOU"};

public:
	bool halvesAreAlike(string s) {
		const int mid = s.size() / 2;
		int a = 0, b = 0;
		for(int i = 0; i < mid; i++)
			a += (vowel.find(s[i]) != vowel.npos);
		for(int i = s.size() - 1; i >= mid; i--)
			b += (vowel.find(s[i]) != vowel.npos);
		return a == b;
	}
};