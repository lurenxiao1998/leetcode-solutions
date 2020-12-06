#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    set<char> tmpMatrix;
    int matrixCount = 0;
    set<char> tmpRow;
    int rowCount = 0;
    set<char> tmpColumn;
    int columnCount = 0;
    for (size_t i = 0; i < 3; i++) {

      for (size_t ii = 0; ii < 3; ii++) {
        tmpMatrix = {};
        matrixCount = 0;
        tmpRow={};
        rowCount=0;

        for (size_t iii = 0; iii < 3; iii++) {
          if (board[i * 3 + ii][iii * 3 + 0] != '.') {
            rowCount += 1;
            tmpRow.insert(board[i * 3 + ii][iii * 3 + 0]);
          }
          if (board[i * 3 + ii][iii * 3 + 1] != '.') {
            rowCount += 1;
            tmpRow.insert(board[i * 3 + ii][iii * 3 + 1]);
          }
          if (board[i * 3 + ii][iii * 3 + 2] != '.') {
            rowCount += 1;
            tmpRow.insert(board[i * 3 + ii][iii * 3 + 2]);
          }
          if (board[i * 3 + 0][ii * 3 + iii] != '.') {
            matrixCount += 1;
            tmpMatrix.insert(board[i * 3 + 0][ii * 3 + iii]);
          }
          if (board[i * 3 + 1][ii * 3 + iii] != '.') {
            matrixCount += 1;
            tmpMatrix.insert(board[i * 3 + 1][ii * 3 + iii]);
          }
          if (board[i * 3 + 2][ii * 3 + iii] != '.') {
            matrixCount += 1;
            tmpMatrix.insert(board[i * 3 + 2][ii * 3 + iii]);
          }
        }
        if (tmpMatrix.size() != matrixCount)
          return false;
        if (tmpRow.size() != rowCount)
          return false;
      }
    }
    for (size_t column = 0; column < 9; column++) {
      tmpColumn = {};
      columnCount = 0;
      for (size_t row = 0; row < 9; row++) {
        if (board[row][column] != '.') {
          tmpColumn.insert(board[row][column]);
          columnCount += 1;
        }
      }
      if (columnCount != tmpColumn.size())
        return false;
    }
    return true;
  }
};