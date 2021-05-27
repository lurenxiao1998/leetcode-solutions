class Solution {
    vector<int> path;
    vector<vector<int>> ans;

    void pathFind(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return ;
        path.push_back(root->val);
        if(root ->left== nullptr&& root->right==nullptr && targetSum==root->val)
            ans.push_back(path);
        if(root->right!=nullptr)
            pathFind(root->right,targetSum-root->val);
        
        if(root->left!=nullptr)
            pathFind(root->left,targetSum-root->val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathFind(root,targetSum);
        return ans;
    }
};