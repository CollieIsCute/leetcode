class Solution {
public:
    int longestPalindrome(string_view s) {
        unordered_set<char> pair;
        auto whole_size = 0;
        for (auto ch : s) {
            if (pair.count(ch)) {
                whole_size += 2;
                pair.erase(ch);

            } else {
                pair.insert(ch);
            }
        }
        whole_size += (!pair.empty());
        return whole_size;
    }
};
