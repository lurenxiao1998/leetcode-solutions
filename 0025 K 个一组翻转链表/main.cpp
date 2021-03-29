class Solution {
ListNode * reverseNodeNextK(ListNode* head, int k) {
    if(k==1){
        return head->next;
    }
    int i=0;
    ListNode * node = head;
    for(;i<k && node != nullptr;i++){
        node = node -> next;
    }
    if(i<k || node == nullptr)
        return nullptr;
    
    ListNode * node1 = head->next;
    ListNode * node2 = node1->next;
    // cout<<" "<<i<<" "<<node1->val<<" "<<node2->val<<endl;
    ListNode * node3 = node2->next;
    for(i=0;i<k-1;i++){
        
        node2 -> next = node1;
        if(i != k-2){
            node1 = node2;
            node2 = node3;
            node3 = node3->next;    
        }
    }
    node1 =head -> next;
    head -> next = node2;
    node1 -> next = node3;
    // cout<<" "<<node2->val<<" "<<node2->next->val<<endl;
    return node1;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode hhead(0,head);
        ListNode *node =&hhead;
        while(node != nullptr){
            node = reverseNodeNextK (node,k);
        }
        return hhead.next;
    }
};