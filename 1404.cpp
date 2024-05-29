class Solution {
public:
    int numSteps(string_view s) {
        const auto whole_size = s.size();
        const auto last_zero_cnt = s.size() - s.find_last_of('1') - 1;
        s.remove_suffix(last_zero_cnt);
        auto one_cnt = 0;
        auto zero_cnt = 0;
        for (const auto c : s) {
            one_cnt += (c == '1');
            zero_cnt += (c == '0');
        }
        return whole_size - 1 + zero_cnt + 2 * (one_cnt > 1);
    }
};
