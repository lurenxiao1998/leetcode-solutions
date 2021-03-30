class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tern=matrix.size()/2;
        for(int i=0;i<tern;i++){
            for(int j=i;j<matrix.size()-i-1;j++){
                swap(matrix[i][j],matrix[j][matrix.size()-i-1]);
                swap(matrix[i][j],matrix[matrix.size()-i-1][matrix.size()-1-j]);
                swap(matrix[i][j],matrix[matrix.size()-1-j][i]);
            }
        }
    }
};