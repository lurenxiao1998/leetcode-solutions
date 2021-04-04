class Solution {

    vector<TreeNode*> dfs(int left,int right){
        if(left>right){
            return {nullptr};
        }
        vector<TreeNode*> res;
        for(int i=left;i<=right;i++){
            vector<TreeNode*> leftTrees = dfs(left,i-1);
            vector<TreeNode*> rightTrees = dfs(i+1,right);
            for(auto &&l:leftTrees){
                for(auto &&r:rightTrees){
                    res.push_back(new TreeNode(i,l,r));
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return {};
        }
        return dfs(1,n);
    }
};