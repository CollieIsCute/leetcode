class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> ss(numRows);
        for (auto i = 0; i < s.size(); i++) {
            auto turn = i % (2 * numRows - 2);
            if (turn < numRows) {
                ss[turn].push_back(s[i]);
            } else {
                ss[2 * numRows - turn - 2].push_back(s[i]);
            }
        }
        return std::accumulate(ss.begin(), ss.end(), string{});
    }
};
