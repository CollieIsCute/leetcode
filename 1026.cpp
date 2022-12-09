// Definition for a binary tree node.
// struct TreeNode {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
// right(right) {}
// };

#include <algorithm>
using namespace std;
class Solution {
public:
	int maxAncestorDiff(TreeNode* root, int min_n = 100000, int max_n = 0) {
		if(!root)
			return 0;
		min_n = min(min_n, root->val);
		max_n = max(max_n, root->val);

		return max({max_n - min_n, maxAncestorDiff(root->left, min_n, max_n),
					maxAncestorDiff(root->right, min_n, max_n)});
	}
};