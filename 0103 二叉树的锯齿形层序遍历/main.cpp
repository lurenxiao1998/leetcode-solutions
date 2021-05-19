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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<TreeNode*> stk{root};
        int n=stk.size();
        int lastn=0;
        vector<vector<int>> ans;
        bool even=false;
        while(lastn!=n){
            deque<int> tmp;
            for(int i=lastn;i<n;i++){
                TreeNode* node = stk[i];
                if(even){
                    tmp.push_front(node->val);
                }else{
                    tmp.push_back(node->val);
                }
                if(node->left)
                    stk.push_back(node->left);
                if(node->right)
                    stk.push_back(node->right);
            }
            lastn=n;
            n=stk.size();
            ans.emplace_back(vector<int>{tmp.begin(),tmp.end()});
            even=!even;
        }
        return ans;
    }
};