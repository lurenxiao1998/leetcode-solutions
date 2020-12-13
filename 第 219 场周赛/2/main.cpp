#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
      char c='0';
      for (auto &&i : n)
      {
        if(i>c){
          c=i;
        }
      }
      return c-'0';
    }
};