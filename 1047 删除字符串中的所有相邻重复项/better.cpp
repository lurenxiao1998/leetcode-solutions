#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string removeDuplicates(string S) {
    string stk;
    for (char ch : S) {
      if(!stk.empty() && stk.back()==ch)
        stk.pop_back();
      else
        stk.push_back(ch);
    }
    return stk;
  }
};