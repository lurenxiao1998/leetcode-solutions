#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  string strAdd(string num1, string num2) {
    int n1size = num1.size();
    int n2size = num2.size();
    string res;
    int jw = 0;
    int r = 0;
    for (int i = 0; i < n1size && i < n2size; i++) {
      r = num1[n1size - i - 1] + num2[n2size - i - 1] - 2 * '0' + jw;
      jw = r / 10;
      res.push_back(r % 10 + '0');
    }
    if (n1size < n2size) {
      for (int i = n1size; i < n2size; i++) {
        r = jw + num2[n2size - i - 1] - '0';
        jw = r / 10;
        res.push_back(r%10 + '0');
      }
    } else if (n1size > n2size) {
      for (int i = n2size; i < n1size; i++) {
        r = jw + num1[n1size - i - 1] - '0';
        jw = r / 10;
        res.push_back(r%10 + '0');
      }
    }

    if (jw != 0)
      res.push_back(jw + '0');
    reverse(res.begin(), res.end());
    return res;
  }

public:
  string multiply(string num1, string num2) {
    if(num2=="0" || num1=="0")
      return "0";
    string res = "0";
    string oneCmultOneS = "";
    string rightzero="";
    int jw = 0;
    int r = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
      oneCmultOneS="";
      r=0;
      jw=0;
      for (int j = num2.size() - 1; j >= 0; j--) {
        r = (num2[j] - '0') * (num1[i] - '0') + jw;
        jw = r / 10;
        oneCmultOneS.push_back(r%10+'0');
      }
      if(jw != 0)
        oneCmultOneS.push_back(jw+'0');
      reverse(oneCmultOneS.begin(),oneCmultOneS.end());
      res=strAdd(res, oneCmultOneS+rightzero);
      rightzero+="0";
    }

    return res;
  }
};
int main(){
  Solution().multiply("11","99");
}