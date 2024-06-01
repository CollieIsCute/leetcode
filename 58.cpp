class Solution {
public:
    int lengthOfLastWord(string_view s) {
        auto last_c = s.find_last_not_of(' ');
        s.remove_suffix(s.size() - last_c - 1);
        return s.size() - s.find_last_of(' ') - 1;
    }
};
