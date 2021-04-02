class Solution {
private:
    vector<vector<bool>> seen;
    vector<vector<char>> board;
    string word;
    bool recursion(int i,int j,int idx){
        if(idx==word.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()  || word[idx] != board[i][j] || seen[i][j])
            return false;
        seen[i][j]=true;
        if(recursion(i-1,j,idx+1))
            return true;
        if(recursion(i,j-1,idx+1))
            return true;
        if(recursion(i+1,j,idx+1))
            return true;
        if(recursion(i,j+1,idx+1))
            return true;

        seen[i][j]=false;
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        seen = vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        this->word=word;
        this->board=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)
                if(recursion(i,j,0))
                    return true;
        }
        return false;
    }
};