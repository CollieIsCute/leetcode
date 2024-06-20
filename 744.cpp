class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        constexpr char MaxCh = 'z' + 1;
        char ret = MaxCh;
        for (const auto l : letters) {
            if (l > target)
                ret = std::min(l, ret);
        }
        if (ret == MaxCh)
            return letters.front();
        return ret;
    }
};
