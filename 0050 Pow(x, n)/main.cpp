#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n==-1){
            return 1/x;
        }

        if( n&1 ){
            return  n>0 ?myPow(x*x,n/2)*x:myPow(x*x,n/2)/x;
        }
        else{
            return myPow(x*x,n/2);
        }

    }
};
int main(int argc, char const *argv[])
{
  Solution().myPow(8,1);
  /* code */
  return 0;
}
