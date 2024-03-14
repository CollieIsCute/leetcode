#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks,
                  int additionalRocks) {
    vector<int> remain(capacity.size());
    for (int i = 0; i < remain.size(); i++) remain[i] = capacity[i] - rocks[i];
    sort(remain.begin(), remain.end());
    int max_i;
    for (max_i = 0; additionalRocks > 0 && max_i < remain.size(); ++max_i)
      additionalRocks -= remain[max_i];
    return additionalRocks >= 0 ? max_i : max_i - 1;
  }
};