
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
	int countNodes(TreeNode* root) {
		int l_height = 1, r_height = 1;
		TreeNode *left = root, *right = root;
		if(!root)
			return 0;
		while(left = left->left)
			++l_height;
		while(right = right->right)
			++r_height;
		if(l_height == r_height)
			return (1 << l_height) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};