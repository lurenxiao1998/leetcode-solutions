#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  bool column[9][9];
  bool row[9][9];
  bool matrix[3][3][9];
  vector<pair<int, int>> a;
  vector<vector<char>> myboard;

  bool recursive(int deep) {
    if (a.size() == deep) {
      return true;
    }
    int i = a[deep].first;
    int j = a[deep].second;
    for (int num = 0; num < 9; num++) {
      if (!column[j][num] && !row[i][num] && !matrix[i / 3][j / 3][num]) {
        column[j][num] = true;
        row[i][num] = true;
        matrix[i / 3][j / 3][num] = true;
        myboard[i][j] = '1' + num;
        if (recursive(deep+1)) {
          return true;
        }
        myboard[i][j] = '.';
        column[j][num] = false;
        row[i][num] = false;
        matrix[i / 3][j / 3][num] = false;
      }
    }
    return false;
  }

public:
  void solveSudoku(vector<vector<char>> &board) {
    memset(row,false,sizeof(row));
    memset(column,false,sizeof(column));
    memset(matrix,false,sizeof(matrix));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.'){
          a.push_back(pair<int, int>{i, j});
        }
        else {
          row[i][board[i][j] - '1'] = true;
          column[j][board[i][j] - '1'] = true;
          matrix[i / 3][j / 3][board[i][j] - '1'] = true;
        }
      }
    }
    myboard = board;
    recursive(0);
    board=myboard;
    return;
  }
};

int main(){
  vector<vector<char>> a={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
  Solution().solveSudoku(a);
}