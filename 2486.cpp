class Solution {
 public:
  int appendCharacters(string_view s, string_view t) {
    for (const auto& c : s) {
      if (c == t.front()) {
        t.remove_prefix(1);
      }
    }
    return t.size();
  }
};
