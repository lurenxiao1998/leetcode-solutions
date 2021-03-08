#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> a;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        partitionL(path,s);
        return a;
    }
    void partitionL(vector<string> &path,string s) {
        if(s==""){
            vector<string> copy(path);
            a.push_back(copy);
            return;
        }
        for (size_t i = 1; i <= s.size(); i++)
        {
            if(isp(s.substr(0,i))){
                path.push_back(s.substr(0,i));
                partitionL(path,s.substr(i));
                path.pop_back();
            }
        }
        
    }
    bool isp(string s){
        int l=0,r=s.length()-1;
        while(r>=l){
            if(s[r]!=s[l]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
int main(){
    auto a=Solution().partition("aab");
    for (auto &&i : a)
    {
        for (auto &&j : i)
        {
            cout<<j;
        }
        
    }
    
    return 0;
}