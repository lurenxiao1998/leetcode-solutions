#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCharacters(string a, string b) {
    vector<int> nb(128, 0);
    vector<int> na(128, 0);
    vector<int> sumnb(128, 0);
    vector<int> sumna(128, 0);
    vector<int> sumfir(128, 0);
    vector<int> sumsec(128, 0);
    vector<int> sumthr(128, 0);
    int allc = a.size() + b.size();
    int allb = b.size();
    int alla = a.size();
    int fir;
    int sec;
    int thr;
    for (size_t i = 0; i < a.size(); i++) {
      na[a[i]]++;
    }
    for (size_t i = 0; i < b.size(); i++) {
      nb[b[i]]++;
    }
    for (size_t i = 97; i < 123; i++) {
      sumthr[i] = nb[i] + na[i];
    }
    thr = allc - *max_element(sumthr.begin(), sumthr.end());
    for (size_t i = 1; i < sumna.size(); i++) {
      na[i] += na[i - 1];
      nb[i] += nb[i - 1];
    }
    for (size_t i = 97; i < 123; i++) {
      sumfir[i] = nb[i] + (alla - na[i]);
      sumsec[i] = na[i] + (allb - nb[i]);
    }
    fir = *min_element(sumfir.begin()+97,sumfir.end()-6);
    sec = *min_element(sumsec.begin()+97,sumsec.end()-6);
    int tmp=min(fir,sec);
    tmp=min(min(fir,sec),thr);
    return min(min(fir,sec),thr);
  }
};

int main(int argc, char const *argv[])
{
  Solution().minCharacters("a","abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
  return 0;
}
