#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode node = ListNode(0, head);
    ListNode *hhead = &node;
    auto next = hhead;
    auto finddx = hhead;
    ListNode *sx, *dx;
    int idx = 1;
    while (next != NULL) {
      if (idx > k) {
        dx = finddx;
        finddx = finddx->next;
      }
      if (idx <= k) {
        sx = next;
      }
      next = next->next;
      idx += 1;
    }
    ListNode *swapf = sx->next;
    ListNode *swapl = dx->next;
    ListNode *tmp = swapf->next;
    if (swapf->next == swapl) {
      sx->next=swapl;
      swapf->next=swapl->next;
      swapl->next=swapf;
    }
    else if(swapl->next == swapf){

      dx->next=swapf;
      swapl->next=swapf->next;
      swapf->next=swapl;
    }
    else{

      swapf->next = swapl->next;
      swapl->next = tmp;

      sx->next = swapl;
      dx->next = swapf;
    }
    return hhead->next;
  }
};