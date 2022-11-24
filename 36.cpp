#include <iostream>
using namespace std;

const int Row_size = 9, Column_size = 9;

bool check_row(const vector<vector<char>>& board, const int row_num){
	bool number_used[10] = {};
	for(const char& ch: board[row_num]){
		if(!std::isdigit(ch))
			continue;
		if(number_used[ch-'0'])
			return false;
		else
			number_used[ch - '0'] = true;
	}
	return true;
}

bool check_column(const vector<vector<char>>& board, const int column_num){
	bool number_used[10] = {};
	for(const auto& row: board){
		if(!std::isdigit(row[column_num]))
			continue;
		if(number_used[row[column_num]-'0'])
			return false;
		else
			number_used[row[column_num] - '0'] = true;
	}
	return true;
}

using block_left_top = std::pair<int, int>;

bool check_block(const vector<vector<char>>& board, const block_left_top& pos){
	bool number_used[10] = {};
	for(int i = pos.first; i < pos.first + 3; i++) {
		for(int j = pos.second; j < pos.second + 3; j++){
			if(!std::isdigit(board[i][j]))
				continue;
			if(number_used[board[i][j] - '0'])
				return false;
			else
				number_used[board[i][j] - '0'] = true;
		}
	}
	return true;
}

class Solution {
public:
	bool isValidSudoku(const vector<vector<char>>& board) {
		print_board(board);
		bool ret = true;
		for(int i = 0; i < board.size(); i++) {
			ret &= check_column(board, i);
			ret &= check_row(board, i);
			if(!ret)
				return ret;
		}

		for(int i = 0; i < board.size(); i+=3)
			for(int j = 0; j < board[i].size(); j+=3)
				ret &= check_block(board, make_pair(i, j));
		return ret;
	}
};