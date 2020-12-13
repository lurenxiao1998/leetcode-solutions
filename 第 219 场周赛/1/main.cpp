#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfMatches(int n) {
      int pairs=0;
      while (n!=1)
      {
        if(n%2==1){
          pairs+=n/2;
          n=n/2+1;
        }
        else{
          pairs+=n/2;
          n=n/2;
        }
          // tern+=1;
      }
      return pairs;
      
    }
};