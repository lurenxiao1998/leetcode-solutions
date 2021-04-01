class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        vector<int> dp(n,1);
        if(obstacleGrid[0][0]==1)
            dp[0]=0;
        for(int i=1 ; i<n ; i++)
            dp[i] = dp[i-1] & ! obstacleGrid[0][i];
        
        for(int i=1; i<m;i++ ){
            dp[0] = dp[0] &  !obstacleGrid[i][0];
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j])
                    dp[j] = 0;
                else
                    dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[n-1];
    }
};