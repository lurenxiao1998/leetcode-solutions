#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string multiply(string num1, string num2) {
    string r = "";
    string base = "";
    for (size_t i = num1.size()-1; i >=0 ; i--) {
      int j = 0;
      int n1 = num1[i] - '0';
      int carry = 0;
      int remainder = 0;
      string tmp = "";
      string tmpsum = "";
      for (j = num2.size()-1; j >= 0; j--) {
        int n2 = num2[j] - '0';
        remainder = (n1 * n2 + carry) % 10;
        carry = (n1 * n2 + carry) / 10;
        tmp = char('0' + remainder) + tmp;
      }
      if (carry > 0)
        tmp = char('0' + carry) + tmp;
      tmp += base;

      for (j = r.size()-1; j >= 0; j--) {
        tmpsum = char('0' + (tmp[j] + carry + r[j] - '0' - '0') % 10) + tmpsum;
        carry = (tmp[j] + carry + r[j] - '0' - '0') / 10;
      }
      for (j = r.size()-1; j < tmp.size(); j--) {
        tmpsum = char('0' + (tmp[j] + carry - '0') % 10) + tmpsum;
        carry = (tmp[j] + carry - '0') / 10;
      }
      if (carry > 0)
        tmpsum = '1' + tmpsum;
      r = tmpsum;
      base += "0";
    }
    return r;
  }
};
int main(int argc, char const *argv[]) {
  Solution().multiply("123", "456");
  return 0;
}
