#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> is(s.size()+1,vector<bool>(s.size()+1,true));
        vector<int> dp(s.size()+1,INT_MAX);
        dp[0]=0;
        for(int i=2;i<s.size()+1;i++){
            for (int j = 0; j < s.size()-i+1; j++){
                is[j][j+i]=is[j+1][j+i-1]?s[j]==s[j+i-1]:false;
            }
        }
        for (size_t i = 1; i < s.size()+1; i++)
        {
            for (size_t j = 0; j < i+1; j++)
            {
                if(is[j][i]){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[s.size()]-1;
    }
};