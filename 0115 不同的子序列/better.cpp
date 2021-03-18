#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long>dp(t.size()+1);
        dp[t.size()]=1;
        for(int i=s.size()-1;i>=0;i--)
        for(int j=0;j<t.size();j++)
        if(s[i]==t[j])
        dp[j]+=dp[j+1];
        return dp[0];
    }
};