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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    TreeNode *prev=nullptr;
    stack<TreeNode *> stk;
    while (stk.size() != 0 || root!=nullptr ) {
    bool aa=!( prev != nullptr && prev->right==root);
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      if (root->right != nullptr && root->right!=prev) {
        stk.push(root);
        root = root->right;
      }else{
        res.push_back(root->val);
        prev = root;
        root = nullptr;
      }
    }
    return res;
  }
};
