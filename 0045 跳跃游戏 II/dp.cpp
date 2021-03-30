class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int minj;
        for(int i=1;i<nums.size();i++){
            minj=INT_MAX;
            for(int j=i-1;j>=0;j--){
                if(nums[j]+j>=i){
                    minj=min(minj,dp[j]+1);
                }
            }
            dp[i]=minj;
        }
        return dp[nums.size()-1];
    }
};