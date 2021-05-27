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
    TreeNode* buildFlat(TreeNode* node){
        if(node == nullptr)
            return node;
        TreeNode* tmp=node->right;
        node->right=node->left;
        node->left=nullptr;
        TreeNode* lastFlatNode = node;
        if(node->right != nullptr)
            lastFlatNode = buildFlat(node->right);
        lastFlatNode->right = tmp;
        if(tmp != nullptr)
            lastFlatNode = buildFlat(tmp);
        return lastFlatNode;
    }
public:
    void flatten(TreeNode* root) {
        buildFlat(root);
    }
};