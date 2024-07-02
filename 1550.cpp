class Solution {
public:
    bool threeConsecutiveOdds(const vector<int>& arr) {
        int cnt = 0;
        for (const auto& n : arr) {
            if (n % 2)
                ++cnt;
            else
                cnt = 0;
            if (cnt >= 3)
                return true;
        }
        return false;
    }
};
