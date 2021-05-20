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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<TreeNode*> stk;
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        int li=0,ri=1;
        stk.push_back(root);
        while(li!=ri){
            vector<int> tmp;
            for(int i =li;i<ri;i++){
                TreeNode* node = stk[i];
                // cout<<li<<" "<<ri<<endl;
                // cout<<node->val<<endl;
                tmp.push_back(node->val);

                if(node->left != nullptr)
                    stk.push_back(node->left);
                if(node->right != nullptr)
                    stk.push_back(node->right);
            }
            li=ri;
            ri=stk.size();
            ans.push_back(tmp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};