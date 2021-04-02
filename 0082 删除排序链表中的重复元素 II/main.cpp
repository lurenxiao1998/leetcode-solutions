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
    ListNode* deleteDuplicates(ListNode* head) {
        int lastnum=-101;
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* hair= new ListNode(0,head);
        ListNode* node=hair,*node2;
        int num=node->next->val;
        while(node != nullptr){
            node2=node->next;
            if( node -> next != nullptr && node2->next !=nullptr &&  node->next->val == node2->next->val){
                int num = node->next->val;
                while(node->next != nullptr && node->next->val==num){
                    node->next=node2->next;
                    node2=node2->next;
                }
            }else{
                node = node->next;
            }
        }
        return hair->next;
    }
};