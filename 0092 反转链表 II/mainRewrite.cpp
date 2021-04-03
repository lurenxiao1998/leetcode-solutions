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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right-left==0)
            return head;
        ListNode* n1,*n2,*n3;
        ListNode tmp=ListNode(0,head);
        ListNode* hair = &tmp;
        n1=head;
        for(int i=1;i<left;i++){
            hair=hair->next;
        }
        n1=hair->next;
        n2=n1->next;
        n3=n2->next;
        for(int i=0;i<right-left;i++){
            n2->next=n1;
            n1=n2;
            n2=n3;
            if(n3!=nullptr){
                n3=n3->next;
            }
        }
        hair->next->next=n2;
        hair->next=n1;
        return tmp.next;
    }
};