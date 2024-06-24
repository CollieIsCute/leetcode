class Solution {
    int count_satisfied_increment(const vector<int>& customers,
                                  const vector<int>& grumpy, int start_min,
                                  int minutes) {
        return std::inner_product(customers.begin() + start_min,
                                  customers.begin() + start_min + minutes,
                                  grumpy.begin() + start_min, 0);
    }

public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        auto base = std::inner_product(
            customers.begin(), customers.end(), grumpy.begin(), 0,
            +[](const int& a, const int& b) { return a + b; },
            +[](int& a, int& b) { return a * (!b); });
        auto start_window =
            count_satisfied_increment(customers, grumpy, 0, minutes);
        auto maxS = base + start_window;
        auto cur = maxS;
        for (auto i = minutes; i < customers.size(); i++) {
            cur += customers[i] * grumpy[i];
            cur -= customers[i - minutes] * grumpy[i - minutes];
            maxS = std::max(cur, maxS);
        }
        return maxS;
    }
};
