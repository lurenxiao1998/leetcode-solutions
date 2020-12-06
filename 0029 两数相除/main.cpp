#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int divide(int dividend, int divisor) {
    int sig = dividend >> 31 ^ divisor >> 31;
    dividend = dividend < 0 ? dividend : -dividend;
    divisor = divisor < 0 ? divisor : -divisor;
    int r = 0;
    int digit = 1;
    int tmpdivisor = divisor;
    while (dividend <= divisor) {
      digit = 1;
      int c=tmpdivisor + tmpdivisor;
      while (c >= dividend && c < 0) {
        tmpdivisor += tmpdivisor;
        digit <<= 1;
        c=tmpdivisor + tmpdivisor;
      }
      dividend -= tmpdivisor;
      tmpdivisor = divisor;
      r -= digit;
    }
    int v=sig<0? r : r==INT_MIN? INT_MAX:-r;
    return sig<0? r : r==INT_MIN? INT_MAX:-r ;
  }
};
int stringToInteger(string input) { return stoi(input); }

int main() {
  int ret = Solution().divide(-2147483648, 3);
  return 0;
}