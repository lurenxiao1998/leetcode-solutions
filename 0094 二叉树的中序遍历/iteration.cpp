// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    auto node = root;
    vector<int> inorder;
    stack<TreeNode *> stk;
    while (node != nullptr || stk.size()) {
      while (node != nullptr) {
        stk.push(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      inorder.push_back(node->val);
      node = node->right;
    }
    return inorder;
  }
};
