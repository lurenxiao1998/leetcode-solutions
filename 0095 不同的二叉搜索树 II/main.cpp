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

    void dfs(vector<TreeNode*>& ans,int lBorder,int rootval,int rBorder){
        
        vector<TreeNode*> leftNodes;
        vector<TreeNode*> rightNodes;
        if(rootval==lBorder+1){
            leftNodes.push_back(nullptr);
        }
        if(rootval==rBorder-1){
            rightNodes.push_back(nullptr);
        }
        // cout<< lBorder<<" "<<rootval<<" "<<rBorder<<endl;
        for( int i =lBorder+1;i<rootval;i++){
            dfs(leftNodes,lBorder,i,rootval);
        }
        for(int i=rootval+1;i<rBorder;i++){
            dfs(rightNodes,rootval,i,rBorder);
        }
        for( int i=0;i<leftNodes.size();i++){
            for( int j=0;j<rightNodes.size();j++){
                ans.push_back( new TreeNode(rootval,leftNodes[i],rightNodes[j]));
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for(int i=1;i<=n;i++){
            dfs(ans,0,i,n+1);
        }
        return ans;
    }
};