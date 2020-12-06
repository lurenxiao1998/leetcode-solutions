#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<int>> columns(9, vector<int>(9, 0));
    vector<vector<int>> rows(9, vector<int>(9, 0));
    vector<vector<int>> matrices(9, vector<int>(9, 0));
    for (int row = 0; row < 9; row++) {
      for (int column = 0; column < 9; column++) {
        char tmp = board[row][column];
        if (tmp != '.') {
          if (columns[column][tmp - '1'] > 0 || rows[row][tmp - '1'] > 0 ||
              matrices[row / 3 * 3 + column/3][tmp - '1'] > 0) {
            return false;
          }
          columns[column][tmp - '1'] = 1;
          rows[row][tmp - '1'] = 1;
          matrices[row / 3 * 3 + column/3][tmp - '1'] = 1;
        }
      }
    }
    return true;
  }
};
int main() {
  vector<vector<char>> a{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution().isValidSudoku(a);
  return 0;
}