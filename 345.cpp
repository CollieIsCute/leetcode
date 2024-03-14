#include <set>
#include <string>
using namespace std;

set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

class Solution {
 public:
  string reverseVowels(string s) {
    for (int hi = s.size() - 1, lo = 0; lo < hi;) {
      auto find_vowel_pair = [&]() -> void {
        while ((vowels.find(s[lo]) == vowels.end()) && lo < hi) ++lo;
        while ((vowels.find(s[hi]) == vowels.end()) && lo < hi) --hi;
      };
      find_vowel_pair();
      if (lo < hi) {
        swap(s[lo], s[hi]);
        ++lo;
        --hi;
      }
    }
    return s;
  }
};