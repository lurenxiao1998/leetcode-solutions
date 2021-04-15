/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isSymmetric(TreeNode * left,TreeNode * right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if( !left || !right ){
            return false;
        }
        return left->val==right->val&isSymmetric(right->right,left->left)&isSymmetric(left->right,right->left);

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isSymmetric(root->left,root->right);
    }
};