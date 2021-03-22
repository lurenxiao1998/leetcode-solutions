struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stk;
    while (stk.size() != 0 || root != nullptr) {
      while (root != nullptr) {
        res.push_back(root->val);
        stk.push(root);
        root=root->left;
      }
      root=stk.top();
      stk.pop();
      root=root->right;
    }
    return res;
  }
};