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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode* l1head=l1,*l2head= l2,*node = &res;
        while( l1 != nullptr || l2 !=nullptr){;
            if( l1 == nullptr ){
                node->next=l2;
                node=l2;
                l2=l2->next;
                continue;
            }
            if(l2 == nullptr){
                node->next=l1;
                node=l1;
                l1=l1->next;
                continue;
            }
            if( l1 -> val > l2-> val ){
                node->next = l2;
                node=l2;
                l2=l2->next;
            }else{
                node->next = l1;
                node=l1;
                l1=l1->next;
            }
        }
        return res.next;
    }
};