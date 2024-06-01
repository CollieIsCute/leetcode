class Solution {
 public:
  string addBinary(string_view a, string_view b) {
    string ret{};
    auto carry_out = 0;
    while (a.size() || b.size()) {
      int this_turn = 0;
      if (a.size()) {
        this_turn += a.back() - '0';
        a.remove_suffix(1);
      }
      if (b.size()) {
        this_turn += b.back() - '0';
        b.remove_suffix(1);
      }
      this_turn += carry_out;
      carry_out = (this_turn > 1);
      this_turn %= 2;
      ret.insert(ret.begin(), this_turn + '0');
    }
    if (carry_out) ret.insert(ret.begin(), carry_out + '0');
    return ret;
  }
};
