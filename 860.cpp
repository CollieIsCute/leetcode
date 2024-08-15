class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        std::unordered_map<int, int> coins = {};
        for (const auto& bill : bills) {
            if (bill == 10) {
                if (coins[5] <= 0)
                    return false;
                coins[5]--;
            }
            if (bill == 20) {
                if (coins[10] > 0 && coins[5] > 0) {
                    coins[5]--;
                    coins[10]--;
                }
                else if (coins[5] >= 3)
                    coins[5] -= 3;
                else return false;
            }
            coins[bill]++;
        }
        return true;
    }
};
