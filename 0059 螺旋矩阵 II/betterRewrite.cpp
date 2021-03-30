class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int up=0,down=n-1,left=0,right=n-1;
        for(int idx=1;idx<=n*n;){
            for(int j = left;j<=right;j++ ){
                res[up][j]=idx++;
            }
            up++;
            for(int i = up;i<=down;i++){
                res[i][right]=idx++;
            }
            right--;
            
            for(int j = right;j >= left;j--){
                res[down][j]=idx++;
            }
            down--;
            for(int i=down;i>=up;i--){
                res[i][left]=idx++;
            }
            left++;
        }
        return res;
    }
};