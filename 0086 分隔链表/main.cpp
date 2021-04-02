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
        vector<int> v1;
        vector<int> v2;
        ListNode* node=head;
        while(node !=nullptr){
            if(node->val<x)
                v1.push_back(node->val);
            else
                v2.push_back(node->val);
            node=node->next;
        }
        node=head;
        for(int i=0;i<v1.size();i++){
            node->val=v1[i];
            node=node->next;
        }
        for(int i=0;i<v2.size();i++){
            node->val=v2[i];
            node=node->next;
        }
        return head;
    }
};