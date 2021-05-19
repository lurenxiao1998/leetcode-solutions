#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int divide(int dividend, int divisor) {
    int s = (dividend >> 31) ^ (divisor >> 31);
    cout<<s<<endl;
    if (dividend > 0) {
      dividend = -dividend;
    }
    if (divisor > 0)
      divisor = -divisor;
    int tmp_divisor = divisor;
    int res = 0;
    int tmp;
    while (dividend <= divisor) {
      int i = -1;
      tmp_divisor = divisor;
      tmp=tmp_divisor + tmp_divisor;
      while (tmp<0 && tmp >= dividend) {
        cout << tmp_divisor << (tmp_divisor +tmp_divisor) << dividend << endl;
        i = i + i;
        tmp_divisor = tmp_divisor + tmp_divisor;
        tmp=int(tmp_divisor + tmp_divisor);
      }

      dividend -= tmp_divisor;
      cout << divisor << " " << dividend << " " << res << " " << i << endl;
      res += i;
      cout << res << endl;
    }
    return s>=0?res==INT_MIN?-(res+1):-res:res;

  }
};