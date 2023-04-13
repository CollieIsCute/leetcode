#include <unordered_set>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
		unordered_set<int> used_spots = {};
		for(const auto& edge : edges) {
			if(auto search = used_spots.find(edge[0]); search != used_spots.end())
				return edge[0];
			else
				used_spots.insert(edge[0]);
			if(auto search = used_spots.find(edge[1]); search != used_spots.end())
				return edge[1];
			else
                used_spots.insert(edge[1]);
		}
        return -1;
	}
};
