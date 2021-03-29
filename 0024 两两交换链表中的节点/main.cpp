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
    ListNode* swapPairs(ListNode* head) {
        ListNode hhead(0,head);
        ListNode *node1=&hhead;
        ListNode *node2=head;
        ListNode *node3;
        while( node1->next !=nullptr && node1->next->next !=nullptr ){
            node2=node1->next;
            node3=node2->next;

            node2->next=node3->next;
            node3->next=node2;
            node1->next=node3;

            node1=node1->next->next;
        }
        return hhead.next;
    }
};