/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
struct TreeNode;
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret, left_subtree, right_subtree;
		if(root) {
			vector<int> left_subtree = std::move(inorderTraversal(root->left));
			vector<int> right_subtree =
				std::move(inorderTraversal(root->right));
			ret.insert(ret.end(), make_move_iterator(left_subtree.begin()),
					   make_move_iterator(left_subtree.end()));
			ret.push_back(root->val);
			ret.insert(ret.end(), make_move_iterator(right_subtree.begin()),
					   make_move_iterator(right_subtree.end()));
		}
		return ret;
	}
};
