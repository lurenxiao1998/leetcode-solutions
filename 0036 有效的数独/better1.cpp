#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<set<char>> columns(9, set<char>{});
    vector<set<char>> rows(9, set<char>{});
    vector<set<char>> matrices(9, set<char>{});
    for (int row = 0; row < 9; row++) {
      for (int column = 0; column < 9; column++) {
        char tmp = board[row][column];
        if (tmp != '.') {
          if (columns[column].find(tmp) != columns[column].end() ||
              rows[row].find(tmp) != rows[row].end() ||
              matrices[column / 3 * 3 + row / 3].find(tmp) !=
                  matrices[column / 3 * 3 + row / 3].end())
            return false;
          columns[column].insert(tmp);
          rows[row].insert(tmp);
          matrices[column / 3 * 3 + row / 3].insert(tmp);
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