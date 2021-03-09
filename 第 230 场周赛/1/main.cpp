#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
      int type=0,num=0;
      if(ruleKey=="type"){
        type=0;
      }else if(ruleKey=="color"){
        type=1;
      }else if(ruleKey=="name"){
        type=2;
      }else{
        return 0;
      }
      for (size_t i = 0; i < items.size(); i++)
      {
        if(items[i][type]==ruleValue)
          num++;
      }
      return num;
    }
};