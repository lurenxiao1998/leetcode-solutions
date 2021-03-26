#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int findroute(vector<vector<int>>& matrix,vector<vector<bool>> &saw,int i,int j,int m,int n){
        if(saw[i][j]){
            return 0;
        }
        saw[i][j]=true;
        int maxL=0;
        if(i+1<m && matrix[i+1][j] > matrix[i][j] ){
            maxL=max(findroute(matrix,saw, i+1, j, m, n),maxL);
        }
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j] ){
            maxL=max(findroute(matrix,saw, i-1, j, m, n),maxL);
        }
        if(j+1<n && matrix[i][j+1] > matrix[i][j] ){
            maxL=max(findroute(matrix,saw, i, j+1, m, n),maxL);
        }
        if(j-1>=0 && matrix[i][j-1] > matrix[i][j] ){
            maxL=max(findroute(matrix,saw, i, j-1, m, n),maxL);
        }
        saw[i][j]=false;
        return maxL+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<bool>> saw(matrix.size(),vector<bool>(matrix[0].size(),false));
        int mmax=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                mmax=max(findroute(matrix, saw, i, j, m, n),mmax);
            }
        }
        return mmax;
    }
};

int main() {
    vector<vector<int>> matrix={{9,9,4},{6,6,8},{2,1,1}};
    Solution().longestIncreasingPath(matrix);
}