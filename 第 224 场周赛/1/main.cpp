#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
      int maxL=min(rectangles[0][0],rectangles[0][1]);
      int num=1;
      for (size_t i = 1; i < rectangles.size(); i++)
      {
        if(maxL < min(rectangles[i][0],rectangles[i][1])){
          maxL=min(rectangles[i][0],rectangles[i][1]);
          num=1;
        }
        else if(maxL == min(rectangles[i][0],rectangles[i][1])){
          num+=1;
        }
      }
      return num;
    }
};