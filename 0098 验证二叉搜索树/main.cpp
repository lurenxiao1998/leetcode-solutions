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
public:
    bool isValidBST(TreeNode* root) {
        TreeNode * node = root;
        vector<TreeNode*> stk;
        long lastnum = LONG_MIN;
        while(node!=nullptr || stk.size()!=0){
            while(node !=nullptr){
                stk.push_back(node);
                node=node->left;
            }
            node=stk.back();
            stk.pop_back();
            if(node->val <= lastnum){
                return false;
            }
            lastnum=node->val;
            node=node->right;
        }
        return true;

    }
};