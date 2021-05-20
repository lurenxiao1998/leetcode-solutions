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
    bool balance;
    int height(TreeNode* n){
        if(n==nullptr)
            return 0;
        int lh=height(n->left),rh=height(n->right);
        if(abs(lh-rh)>1)
            balance&=false;
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        balance=true;
        height(root);
        return balance;
    }
};