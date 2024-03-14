
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

bool is_in_range(TreeNode* target, int low, int high) {
  if (low <= target->val && target->val <= high)
    cout << target->val << " is in range\n";
  return low <= target->val && target->val <= high;
}

class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    int ret_val = 0;
    if (!root) return ret_val;
    if (is_in_range(root, low, high)) ret_val = root->val;
    return ret_val + rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  }
};