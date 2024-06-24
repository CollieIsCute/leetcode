class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        queue<int> windows;
        auto flipCnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (!windows.empty() && i > windows.front()) {
                windows.pop();
            }
            nums[i] ^= windows.size() & 1;
            if (!nums[i]) {
                ++flipCnt;
                if (i + k - 1 >= nums.size())
                    return -1;
                windows.emplace(i + k - 1);
            }
        }
        return flipCnt;
    }
};
