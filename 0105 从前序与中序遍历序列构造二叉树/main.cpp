class Solution {
    TreeNode* buildTreeRecursion(vector<int> preorder, vector<int> inorder) {
        if(inorder.size()==0)
            return nullptr;
        if(inorder.size()==1){
            return new TreeNode(inorder[0],nullptr,nullptr);
        }
        int x = preorder[0];
        TreeNode* node = new TreeNode(x);
        auto ix = find(inorder.begin(),inorder.end(),x);
        
        vector<int> il = vector<int>(inorder.begin(),ix);
        vector<int> ir = vector<int>(ix+1,inorder.end());
        auto tmp=il.size();
        vector<int> pl = vector<int>(preorder.begin()+1 , preorder.begin()+1+il.size());
        vector<int> pr = vector<int>(preorder.begin()+1+il.size() , preorder.end());

        node->left = buildTreeRecursion( pl, il);
        node->right = buildTreeRecursion( pr, ir);
        return node;
    }
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        return buildTreeRecursion(preorder,inorder);
    }
};