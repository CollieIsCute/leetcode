#include <functional>
#include <vector>
using namespace std;
// Definition for a binary tree node.
// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode* left, TreeNode* right)
// 		: val(x), left(left), right(right) {}
// };

void get_leaves(TreeNode* root, vector<int>& leaves) {
  if (!root) return;
  if (!root->left && !root->right) leaves.push_back(root->val);
  get_leaves(root->left, leaves);
  get_leaves(root->right, leaves);
}

class Solution {
 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    get_leaves(root1, leaves1);
    get_leaves(root2, leaves2);
    return leaves1 == leaves2;
  }
};