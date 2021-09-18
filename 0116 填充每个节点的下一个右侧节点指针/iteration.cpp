class Solution {
public:
    Node* connect(Node* root) {
        Node* leftmost=root;
        while(leftmost!=nullptr && leftmost->left!=nullptr){
            auto head = leftmost;
            while(head->next != nullptr){
                head->left->next=head->right;
                head->right->next=head->next->left;
                head = head->next;
            }
            head->left->next=head->right;
            leftmost=leftmost->left;
        }
        return root; 
    }
};