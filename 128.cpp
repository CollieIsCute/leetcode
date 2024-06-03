class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> exist;
        for(auto& n: nums){
            exist.insert(n);
        }
        auto MaxCnt = 0;
        for(auto n: nums){
            auto cnt = 1;
            if(exist.contains(n) && !exist.contains(n-1)){
                while(exist.contains(++n))
                cnt++;
            }
            MaxCnt = max(MaxCnt, cnt);
        }
        return MaxCnt;
    }
};
