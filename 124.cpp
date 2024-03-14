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
  int all_time_max;

 public:
  Solution() : all_time_max(INT_MIN) {}
  int maxPathSum(TreeNode* root) {
    buttom_up(root);
    return all_time_max;
  }

  int buttom_up(TreeNode* root) {
    if (!root) return 0;
    int ret = 0, l_sub_max = buttom_up(root->left),
        r_sub_max = buttom_up(root->right);
    ret = root->val + max({0, l_sub_max, r_sub_max});
    all_time_max = max({all_time_max, ret, root->val + l_sub_max + r_sub_max});
    return ret;
  }
};