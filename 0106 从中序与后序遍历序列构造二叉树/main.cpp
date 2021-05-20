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
    TreeNode* buildTreeRecursion(vector<int>& inorder,int inorderLeft,int inorderRight,vector<int>& postorder,int postorderLeft,int postorderRight){
        if(postorderRight-postorderLeft==0){
            return nullptr;
        }
        int val = postorder[postorderRight-1];
        TreeNode* node = new TreeNode(val);
        auto inordermid = find(inorder.begin()+inorderLeft,inorder.begin()+inorderRight,val)-inorder.begin();

        node->left = buildTreeRecursion(inorder,inorderLeft,inordermid,postorder,postorderLeft ,postorderLeft+inordermid-inorderLeft );
        node->right = buildTreeRecursion(inorder,inordermid+1,inorderRight,postorder,postorderLeft+inordermid-inorderLeft ,postorderRight-1 );
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeRecursion(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};