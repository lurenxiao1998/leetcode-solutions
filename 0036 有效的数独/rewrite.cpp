class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> column(9,vector<bool>(9,false));
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> matrix(9,vector<bool>(9,false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                int num = board[i][j]-'1';
                if( num >= 0 && num <= 9){
                    if(column[j][num] || row[i][num] || matrix[(i/3)*3+j/3][num] ){
                        return false;
                    }
                    column[j][num] = true;
                    row[i][num]=true;
                    matrix[(i/3)*3+j/3][num]=true;
                }
            }
        }
        return true;
    }
};