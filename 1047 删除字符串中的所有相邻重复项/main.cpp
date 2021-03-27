#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string removeDuplicates(string S) {
    int idx = 0;
    while (idx + 1 < S.size()) {
      if (S[idx] == S[idx + 1]) {
        S.erase(idx, 2);
        if (idx > 0) {
          idx--;
        }
      } else {
        idx++;
      }
    }
    return S;
  }
};