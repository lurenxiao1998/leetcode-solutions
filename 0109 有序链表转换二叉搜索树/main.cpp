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
    TreeNode* buildTree(ListNode* head,ListNode* tail) {
        if(head==tail){
            return nullptr;
        }
        ListNode* qP=head,*sP=head;
        while(qP->next!=tail && qP->next->next!=tail){
            sP=sP->next;
            qP=qP->next->next;
        }
        TreeNode* node = new TreeNode(sP->val);
        node->left = buildTree(head,sP);
        node->right = buildTree(sP->next,tail);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head,nullptr);
    }
};