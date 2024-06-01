class Solution {
 public:
  int strStr(string_view haystack, string_view needle) {
    auto find = haystack.find(needle);
    if (find == string_view::npos) return -1;
    return find;
  }
};
