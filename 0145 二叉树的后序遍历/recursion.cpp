#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
private:
  vector<int> res;
  void recPostorder(TreeNode * node){
    if(node== nullptr)
      return;
    recPostorder(node->left);
    recPostorder(node->right);
    res.push_back(node->val);
  }
public:
  vector<int> postorderTraversal(TreeNode *root) {
    recPostorder(root);
    return res;
  }
};