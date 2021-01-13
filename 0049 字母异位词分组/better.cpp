#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> a;
    for (auto &&str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      a[key].emplace_back(str);
    }
    
    vector<vector<string>> tmp;
    for (auto &&pair : a)
    {
      tmp.emplace_back(pair.second);
    }
    

    return tmp;
  }
};
int main(){
  vector<string> strs{"eat","tea","tan","ate","nat","bat"};
  Solution().groupAnagrams(strs);
  return 0;
}