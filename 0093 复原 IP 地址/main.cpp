#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> res;
    vector<string> t;
    void dfs(string s,int idx,int blank){
        if(blank==0){
            res.push_back(t);
        }
        if(s.size()-idx>blank*3|| s.size()-idx<blank)
            return;
        int size = min(3, int(s.size()) -idx-blank+1);
        int size=min(3,1);
        if(s[idx]=='0'){
            t.push_back("0");
            dfs(s,idx+1,blank-1);
            t.pop_back();
        }
        else{
            for(int i =1;i<=size;i++){
                int num = atoi( s.substr(idx,i) );
                if(0<num && num<=255){
                    t.push_back(s.substr(idx,i));
                    dfs(s,idx+i,blank-1);
                    t.pop_back();
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,4);
        vector<string >ans;
        string tmp="";
        for(int i=0;i<res.size();i++){
            tmp=res[0]+"."+res[1]+"."+res[2]+"."+res[3];
            ans.push_back(tmp);
        }
        return ans;
    }
};