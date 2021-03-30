#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<int>> a;
        for(int i=0;i<strs.size();i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            a[tmp].push_back(strs[i]);
        }
        for(auto &&it:a){
            res.push_back(it.second);
        }
        return res;
    }
};