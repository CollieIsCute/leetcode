#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    using Property = vector<int>;
    using Properties = vector<Property>;
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
	int ret = 0;
	sort(properties.begin(), properties.end(), Solution::compare);
	int max = INT_MIN;
	for(int i = 0; i < properties.size(); i++){
	    if(max > properties[i][1])
		ret++;
	    else if (max < properties[i][1])
		max = properties[i][1];
	}
	return ret;
    }
    static bool compare(Property& a, Property&b){
	if(a[0] == b[0])
	    return a[1] < b[1];
	else
	    return a[0] > b[0];
    }
};
