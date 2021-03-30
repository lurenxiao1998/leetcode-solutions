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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr|| head->next==nullptr){
            return head;
        }
        ListNode hair(0,head);
        ListNode * node=head;
        int n=1;
        while(node->next != nullptr){
            node=node->next;
            n++;
        }

        node->next=head;

        k=k%n;
        node=&hair;
        for(int i=0;i < n-k;i++){
            node=node->next;
        }
        ListNode *nhead=node->next;
        node->next=nullptr;
        return nhead;

    }
};