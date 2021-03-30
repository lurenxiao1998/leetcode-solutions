class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> r;
    int m=matrix.size(),n=matrix[0].size();
    int terns = min(m+1,n+1)/2;
    // cout<<terns<<endl;
    for(int tern=0;tern < terns; tern++){

        // cout<<tern<<" 1 "<<n-tern<<endl;
        for(int j = tern;j < n-tern;j++){
            r.push_back(matrix[tern][j]);
        }
        if(tern+tern+1==m){
            break;
        }
        // cout<<n-tern <<" "<<tern+1<<" 2 "<<m-tern<<endl;
        for(int i = tern+1;i < m - tern ; i++){
            r.push_back(matrix[i][n-tern-1]);
        }

        if(tern+tern+1==n){
            break;
        }
        // cout<<m-tern-1<<" "<<n-tern-1<<" 3 "<<tern<<endl;
        for(int j = n-tern-2;j>=tern;j--){
            r.push_back(matrix[m-tern-1][j]);
        }
        if(tern+tern==m){
            break;
        }
        // cout<<m-tern-1<<" 4 "<<tern<<endl;
        for(int i=m-tern-2;i>tern;i--){
            r.push_back(matrix[i][tern]);
        }
    }
    
    return r;
  }
};