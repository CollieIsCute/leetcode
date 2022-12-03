#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

using Freq_pair = pair<char, int>;

class Solution {
public:
	string frequencySort(string s) {
		map<char, int> freq;
		for(const auto& ch : s)
			++freq[ch];
		auto cmp = [](const Freq_pair& a, const Freq_pair& b) -> bool {
			return a.second < b.second;
		};
		priority_queue<Freq_pair, vector<Freq_pair>, decltype(cmp)> pq(cmp);
		for(const auto& elem : freq)
			if(elem.second)
				pq.push(elem);
		string ret;
		while(!pq.empty()) {
			ret += string(pq.top().second, pq.top().first);
			pq.pop();
		}
        return ret;
	}
};