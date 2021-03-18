/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode rhead = ListNode(0,head);
    ListNode *hhead = &rhead;
    ListNode *Rlast;

    for (int i = 0; i < left - 1; i++) {
      hhead = hhead->next;
    }
    Rlast = hhead->next;
    if (Rlast == nullptr)
      return rhead.next;

    ListNode *node = Rlast->next;
    ListNode *lnode = Rlast;
    for (int i = 0; i < right - left; i++) {
      ListNode *tmp = node->next;
      node->next = lnode;
      lnode = node;
      node = tmp;
    }
    if (Rlast == nullptr)
      return rhead.next;
    Rlast->next=node;
    hhead->next=lnode;
    return rhead.next;
  }
};