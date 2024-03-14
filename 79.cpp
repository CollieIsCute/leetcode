#include <iostream>
#include <map>
#include <vector>
using namespace std;
using Pos = pair<int, int>;
using Board = vector<vector<char>>;

namespace {
Pos add(const Pos& a, const Pos& b) {
  return Pos(a.first + b.first, a.second + b.second);
}

bool safe_pos(const Board& board, const Pos& pos) {
  if (0 <= pos.first && pos.first < board.size())
    if (0 <= pos.second && pos.second < board[0].size()) return true;
  return false;
}

bool dfs(Board& board, const Pos pos, const string& word,
         const int word_index) {
  static const vector<pair<int, int>> direct = {
      {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  if (!safe_pos(board, pos)) return false;
  if (board[pos.first][pos.second] == word[word_index])
    if (word_index == word.size() - 1)
      return true;
    else {
      for (const auto& d : direct) {
        board[pos.first][pos.second] = '0';
        if (dfs(board, add(pos, d), word, word_index + 1)) return true;
        board[pos.first][pos.second] = word[word_index];
      }
    }
  return false;
}

void rearrange_word(const vector<vector<char>>& board, string& word) {
  map<char, int> alphabets;
  for (const auto ch : word) alphabets[ch] += 1;
  if (alphabets[word.back()] < alphabets[word.front()])
    reverse(word.begin(), word.end());
}
}  // namespace

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    rearrange_word(board, word);
    bool ret = false;
    for (size_t i = 0; i < board.size(); i++)
      for (size_t j = 0; j < board[i].size(); j++)
        ret |= dfs(board, Pos{i, j}, word, 0);
    return ret;
  }
};