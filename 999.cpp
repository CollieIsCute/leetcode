#include <vector>
using namespace std;

using Position = pair<int, int>;

namespace {

Position get_sum(const Position& a, const Position& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

bool is_in_board(const Position& pos, const vector<vector<char>>& board) {
  return 0 <= pos.first && pos.first < board.size() && 0 <= pos.second &&
         pos.second < board.at(0).size();
}

Position find_rook(const vector<vector<char>>& board) {
  Position ret;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == 'R') ret = make_pair(i, j);
    }
  }
  return ret;
}
}  // namespace

class Solution {
 public:
  int numRookCaptures(const vector<vector<char>>& board) {
    auto black_available = [&board](const Position& now,
                                    const Position& next_move) -> bool {
      Position new_pos = get_sum(now, next_move);
      while (is_in_board(new_pos, board)) {
        const auto& this_ch = board[new_pos.first][new_pos.second];
        if (this_ch == 'p')
          return true;
        else if (this_ch == 'B')
          return false;
        else
          new_pos = get_sum(new_pos, next_move);
      }
      return false;
    };
    int cnt = 0;
    Position rook_pos = find_rook(board);
    cnt += black_available(rook_pos, make_pair(0, -1));
    cnt += black_available(rook_pos, make_pair(0, 1));
    cnt += black_available(rook_pos, make_pair(-1, 0));
    cnt += black_available(rook_pos, make_pair(1, 0));
    return cnt;
  }
};