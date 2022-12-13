#include <vector>
using namespace std;

bool check_valid(const int i, const int j, const vector<vector<int>>& matrix) {
	if(i < 0 || i >= matrix.size())
		return false;
	if(j < 0 || j >= matrix[i].size())
		return false;
	return true;
}

void update_cell(const int i, const int j, vector<vector<int>>& matrix) {
	int min_val = INT_MAX;
	for(int bias = -1; bias < 2; bias++)
		if(check_valid(i + 1, j + bias, matrix)
		   && min_val > matrix[i + 1][j + bias])
			min_val = matrix[i + 1][j + bias];
	matrix[i][j] += min_val;
	return;
}

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		for(int i = matrix.size() - 2; i >= 0; --i)
			for(int j = 0; j < matrix[i].size(); j++)
				update_cell(i, j, matrix);
		int ret_min = INT_MAX;
		for(const int elem : matrix[0])
			ret_min = ret_min > elem ? elem : ret_min;
		return ret_min;
	}
};