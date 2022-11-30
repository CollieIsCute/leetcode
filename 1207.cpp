#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> occurrence;
		for(const auto& n : arr)
			++occurrence[n];
		set<int> check_unique;
		for(const auto& i : occurrence) {
			if(i.second && check_unique.find(i.second) == check_unique.end())
				check_unique.insert(i.second);
			else {
				return false;
			}
		}
		return true;
	}
};