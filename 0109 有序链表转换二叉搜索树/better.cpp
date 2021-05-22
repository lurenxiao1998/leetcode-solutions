/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getLength(ListNode* node){
        int ans=0;
        for(;node!=nullptr;++ans,node=node->next);
        return ans;
    }
    TreeNode* inorder(ListNode* &head,int left,int right){
        if(left>right){
            return nullptr;
        }
        int mid = (left+right)>>1;
        TreeNode* node = new TreeNode();
        node ->left = inorder(head,left,mid-1);
        node ->val=head->val;
        head = head->next;
        node->right = inorder(head,mid+1,right);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLength(head);
        return inorder(head,0,len-1);
    }
};