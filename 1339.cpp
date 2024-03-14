
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

class Solution {
  long long totalSum = 0, result = 0;
  const static int MOD = 1e9 + 7;

 public:
  int maxProduct(TreeNode* root) {
    totalSum = get_sum(root);
    buttom_up_update_result(root);
    return result % MOD;
  }
  int get_sum(TreeNode* root) {
    if (!root) return 0;
    return root->val + get_sum(root->left) + get_sum(root->right);
  }
  int buttom_up_update_result(TreeNode* root) {
    if (!root) return 0;
    int tmp_sum = root->val + buttom_up_update_result(root->left) +
                  buttom_up_update_result(root->right);
    result = max(result, tmp_sum * (totalSum - tmp_sum));
    return tmp_sum;
  }
};