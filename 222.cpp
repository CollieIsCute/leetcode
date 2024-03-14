
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//     right(right) {}
// };
#include <cmath>
#include <iostream>
using namespace std;
bool left_right_same_height(TreeNode* root) {
  TreeNode *left = root, *right = root;
  for (; left && right; left = left->left, right = right->right)
    ;
  return left == right;  // means both nullptr
}

class Solution {
 public:
  int countNodes(TreeNode* root, int current = 1) {
    if (left_right_same_height(root)) {
      TreeNode* l = root;
      while (l && (l = l->left)) current = 2 * current + 1;
      return current * (bool)root;
    }
    if (!left_right_same_height(root->right))
      return countNodes(root->right, 2 * current + 1);
    return countNodes(root->left, current * 2);
  }
};