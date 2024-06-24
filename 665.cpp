class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int past = 0;
        nums.emplace(nums.begin(), -100001);
        nums.emplace(nums.end(), 100001);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] <= nums[i + 1])
                continue;
            if (past) {
                return false;
            }
            if (i+1< nums.size() && i-1 >=0 && nums[i-1] <= nums[i+1]) {
                past = nums[i];
                continue;
            }
            else if(i+2 < nums.size() && nums[i] < nums[i+2]){
              past = nums[i+1];
              continue;
            }
            return false;
        }
        return true;
    }
};
