#include <vector>
using namespace std;
using Pos = pair<int, int>;
using Board = vector<vector<char>>;

namespace {
Pos add(const Pos& a, const Pos& b) {
	return Pos(a.first + b.first, a.second + b.second);
}

bool safe_pos(const Board& board, const Pos& pos) {
	if(0 <= pos.first && pos.first < board.size())
		if(0 <= pos.second && pos.second < board[0].size())
			return true;
	return false;
}

bool bfs(Board board, Pos pos, const string& word, int word_index) {
	board[pos.first][pos.second] = '0';
	if(!safe_pos(board, pos))
		return false;
	if(board[pos.first][pos.second] == word[word_index]) {
		if(word_index == word.size() - 1)
			return true;
		else {
			bool ret = false;
			for(const auto& d : direct)
				ret |= bfs(Board(board), add(pos, d), word, word_index + 1);
			return ret;
		}
	}
	else
		return false;
}
}  // namespace

class Solution {
	const vector<pair<int, int>> direct = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

public:
	bool exist(vector<vector<char>>& board, string word) {
		bool ret = false;
		for(size_t i = 0; i < board.size(); i++) {
			for(size_t j = 0; j < board[i].size(); j++) {
				ret |= bfs(Board(board), Pos{i, j}, word, 0);
			}
		}
		return ret;
	}
};