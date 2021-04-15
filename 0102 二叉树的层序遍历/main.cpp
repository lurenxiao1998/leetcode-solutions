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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *node=root;
        q.push(node);
        int currentNodeSize;
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        while(q.size()!=0){
            vector<int> tmp{};
            currentNodeSize = q.size();
            for(int i=0;i<currentNodeSize;i++){
                node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                tmp.push_back(node->val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};