#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == 0) {
      return 0;
    }
    if (dividend == -2147483648 and divisor == -1) {
      return 2147483647;
    }
    if (dividend == 2147483647 and divisor == 1) {
      return 2147483647;
    }
    if (dividend == -2147483648 and divisor == 1) {
      return -2147483648;
    }
    int quotient = 0;
    int less = dividend;

    if (less < 0) {
      if (divisor < 0) {
        while (less <= 0) {
          less -= divisor;
          quotient += 1;
        }
        return quotient - 1;
      } else {
        while (less <= 0) {
          less += divisor;
          quotient -= 1;
        }
        return quotient + 1;
      }
    } else {
      if (divisor > 0) {
        while (less >= 0) {
          less -= divisor;
          quotient += 1;
        }

        return quotient - 1;
      } else {
        while (less >= 0) {
          less += divisor;
          quotient -= 1;
        }
        return quotient + 1;
      }
    }
  }
};