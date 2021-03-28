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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode hhead(0,head);
        ListNode* qi=&hhead,*si=&hhead;
        for(int i=0;i<n;i++){
            qi=qi->next;
        }
        while(qi->next != nullptr){
            qi=qi->next;
            si=si->next;
        }
        si->next=si->next->next;
        return hhead.next;
    }
};