/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node;
        ListNode * n1=l1,*n2=l2;
        int num1,num2;
        int jw=0,h=0;
        ListNode head=ListNode();
        node = &head;
        for(;n1!=nullptr || n2!= nullptr || jw!=0;){
            num1 = n1==nullptr ? 0:n1->val;
            num2 = n2==nullptr ? 0:n2->val;
            h = num1+num2+jw;
            jw=h/10;
            n2 = n2 == nullptr ? nullptr : n2->next;
            n1 = n1 == nullptr ? nullptr:n1->next;
            node->next=new ListNode(h%10);
            node=node->next;
        }
        return head.next;
    }
};