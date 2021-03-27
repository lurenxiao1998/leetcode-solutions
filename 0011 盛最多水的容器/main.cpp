#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto li=height.begin(),ri=height.end()-1;
        int maxSize = min(*li,*ri)*(ri-li);
        int size=0;
        int hli=0,hri=0;
        while(ri>li){
            hri=*ri;
            hli=*li;
            if( hli  > hri){

                while( ri> li && *--ri > hri ){
                }
                size=min(*li,*ri)*(ri-li);
                if(size>maxSize){
                    maxSize=size;
                }
            }
            else{
                while( ri> li && *++li > hli ){
                    cout<< "2:" << *li;
                }
                size=min(*li,*ri)*(ri-li);
                if(size > maxSize){
                    maxSize=size;
                }
            }
        }
        return maxSize;
    }
};