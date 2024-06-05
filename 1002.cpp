class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<char> inter(words[0].begin(), words[0].end());
    ranges::sort(inter);
    for (const auto& w : words) {
      vector<char> tmp;
      vector<char> cur(w.begin(), w.end());
      ranges::sort(cur);
      ranges::set_intersection(inter, cur, back_inserter(tmp));
      inter = std::move(tmp);
    }
    vector<string> ret;
    for (const auto ch : inter) {
      ret.push_back({ch});
    }
    return ret;
  }
};
