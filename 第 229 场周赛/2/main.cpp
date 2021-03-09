#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
      vector<int> m(boxes.size(),0);
      vector<int> ltr(boxes.size(),0);
      vector<int> rtl(boxes.size(),0);
      for (size_t i = 0; i < boxes.size()-1; i++)
      {
        if(boxes[i]=='1'){
          ltr[i+1]=1;
        }
      }
      for (size_t i = 1; i < boxes.size(); i++)
      {
        if(boxes[i]=='1'){
          rtl[i-1]=1;
        }
      }
      for (size_t i = 1; i < boxes.size(); i++)
      {
        ltr[i]=ltr[i]+ltr[i-1];
        rtl[boxes.size()-i-1] = rtl[boxes.size()-i-1]+rtl[boxes.size()-i];
      }
      for (size_t i = 1; i < boxes.size(); i++)
      {
        ltr[i]=ltr[i]+ltr[i-1];
        rtl[boxes.size()-i-1] = rtl[boxes.size()-i-1]+rtl[boxes.size()-i];
      }
      
      for (size_t i = 0; i < boxes.size(); i++)
      {
        m[i]=ltr[i]+rtl[i];
      }
      return m;
    }
};