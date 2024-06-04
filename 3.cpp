class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        unordered_set<char> seen;
        auto left = 0;
        auto maxlen = seen.size();
        for (auto ch : s) {
            if (!seen.count(ch)) {
                seen.insert(ch);
                maxlen = std::max(maxlen, seen.size());
            } else {
                for (; seen.count(ch); left++) {
                    seen.erase(s[left]);
                }
                seen.insert(ch);
            }
        }
        return maxlen;
    }
};
