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

struct comp{
    bool operator() (ListNode * const a,ListNode * const b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode * node=&head;
        priority_queue<ListNode *,vector<ListNode *> ,comp > h;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]!=nullptr)
                h.push(lists[i]);
        }
        while( h.size() >0 ){
            node->next=h.top();
            node=node->next;
            h.pop();
            if( node->next != nullptr)
                h.push(node->next);
        }
        return head.next;
    }
};