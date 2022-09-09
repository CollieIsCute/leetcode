#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ret;
        k %= nums.size();
        for(int i = 0; i < nums.size(); i++){
            int new_index = (i+nums.size()-k)%nums.size();
            ret.emplace_back(nums[new_index]);
        }
        nums = std::move(ret);
    }
};
