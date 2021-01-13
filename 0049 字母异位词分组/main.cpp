#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> a;
    
    for (size_t i = 0; i < strs.size(); i++) {
      string tmpstr = strs[i];
      bool newType = true;
      sort(tmpstr.begin(),tmpstr.end());
      for (auto &&st : a)
      {
        if(tmpstr == st[0]){
          st.push_back(strs[i]);
          newType=false;
        }
      }
      if(newType){
        vector<string> tmp{tmpstr,strs[i]};
        a.push_back(tmp);
      }
    }
    for (size_t i = 0; i < a.size(); i++)
    {
      a[i].erase(a[i].begin(),a[i].begin()+1);
    }
    
    return a;
  }
};
int main(){
  vector<string> strs{"eat","tea","tan","ate","nat","bat"};
  Solution().groupAnagrams(strs);
  return 0;
}