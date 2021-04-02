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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* n1hair=new ListNode(0);
        ListNode* n1node=n1hair;
        ListNode* n2hair=new ListNode(0);
        ListNode* n2node=n2hair;
        ListNode* node=head;
        while(node !=nullptr){
            if(node->val<x){
                n1node->next=new ListNode(node->val);
                n1node=n1node->next;
            }
            else{
                n2node->next=new ListNode(node->val);
                n2node = n2node->next;
            }
            node=node->next;
        }
        n1node->next=n2hair->next;
        return n1hair->next;
    }
};