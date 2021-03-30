class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int idx=1;
        int terns=n/2;
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int tern=0;tern<terns;tern++){
            for(int j = tern;j<n-tern;j++ ){
                int i = tern;
                res[i][j]=idx++;
            }

            for(int i=tern+1;i<n-tern;i++){
                int j = n-tern-1;
                res[i][j]=idx++;
            }
            // cout<<n-tern-1<<" "<<tern<<endl;
            for(int j = n-tern-2;j>=tern;j--){
                int i = n-tern-1;
                res[i][j]=idx++;
            }
            for(int i=n-tern-2;i>=tern+1;i--){
                int j=tern;
                res[i][j]=idx++;
            }
        }
        if(n&1){
            res[n/2][n/2]=n*n;
        }
        return res;
    }
};