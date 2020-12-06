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

      while (tmpdivisor + tmpdivisor >= dividend && tmpdivisor + tmpdivisor < INT_MIN) {
        tmpdivisor += tmpdivisor;
        digit <<= 1;
      }
      dividend -= tmpdivisor;
      tmpdivisor = divisor;
      r += digit;
    }
    return sig<0?-r:r;
  }
};
int stringToInteger(string input) { return stoi(input); }

int main() {
  int a=INT_MIN;
  int ret = Solution().divide(INT_MIN, 1);
  return 0;
}