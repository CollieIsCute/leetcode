class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto nmin = nums.front();
        auto nmax = nums.front();
        for (const auto n : nums) {
            nmin = std::min(n, nmin);
            nmax = std::max(n, nmax);
        }
        return std::gcd(nmin, nmax);
    }
};
