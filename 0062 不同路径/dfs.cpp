class Solution {
private:
    int dfs(vector<vector<int>>& ans,int m,int n,int i,int j){
        if(i==m-1 && j==n-1)
            return 0;
        if(ans[i][j]){
            return ans[i][j];
        }
        int res=0;
        if(i < m - 1){
            res += dfs(ans,m,n,i + 1,j);
        }
        if(j < n-1){
            res += dfs(ans,m,n,i,j+1);
        }
        if(j < n-1 && i < m - 1)
            res+=1;
        ans[i][j]=res;
        return res;

    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        return dfs(ans,m,n,0,0) + 1;
    }
};