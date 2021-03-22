class Solution {
private:
  void recur(TreeNode* node,vector<int> &res){
    if(node ==nullptr)
      return;
    res.push_back( node->val );
    recur(node->left,res);
    recur(node->right,res);
  }
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      recur(root,res);
      return res;
    }
};