class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<bool> dp(s2.size()+1,false);
        dp[0]=true;

        if(s1.size()+s2.size() !=s3.size()){
            return false;
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i]==s3[i]){
                dp[i+1] = dp[i];
            }
        }

        for(int i=1;i<=s1.size();i++){
            if(s3[i-1]!=s1[i-1]){
                dp[0]=false;
            }
            for(int j=1;j<=s2.size();j++){
                int p=i+j-1;
                if(s3[p]!=s1[i-1]){
                    dp[j] = false;
                }
                if(s3[p]==s2[j-1]){
                    dp[j] = dp[j]|dp[j-1];
                }
            }
        }
        return dp[s2.size()];

    }
};