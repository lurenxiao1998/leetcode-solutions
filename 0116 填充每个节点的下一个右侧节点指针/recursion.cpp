class Solution {
  int depth, prevDepth;
public:
    Solution(){
      depth = 0;
      prevDepth = 1;
    }
    void recursive(Node* node){
        if(node == nullptr)
            return;
        if(node->left != nullptr && node->right != nullptr){
            depth+=2;
            node->left->next = node->right;
            if(node->next !=nullptr)
                node->right->next = node->next->left;
        }
        recursive(node->next);
        prevDepth--;
        if(! prevDepth ){
            prevDepth = depth;
            depth = 0;
            recursive(node->left);
        }
    }
    Node* connect(Node* root) {
        recursive(root);
        return root; 
    }
};