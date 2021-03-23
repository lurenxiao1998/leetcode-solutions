#include <string>
#include <vector>
// #include <pair>
using namespace std;
class Solution {

  vector<vector<int>> r;
  vector<int> case1;
  void solveNQueens(int queenNum, int n) {
    if (queenNum == n) {
      r.push_back(vector<int>(case1));
      return;
    }
    for (int column = 0; column < n; column++) {
      bool noAttack = true;
      for (int queen = 0; queen < case1.size(); queen++) {
        noAttack &= heli(queen, case1[queen], queenNum, column);
      }
      if (noAttack) {
        case1.push_back(column);
        solveNQueens(queenNum + 1, n);
        case1.pop_back();
      }
    };
  }
  bool heli(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2 || y1 - y2 == x1 - x2 || y1 - y2 == x2 - x1)
      return false;
    return true;
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    solveNQueens(0, n);
    vector<vector<string>> s;
    string temp(n,'.');
    for (int i = 0; i < r.size(); i++) {
      vector<string> cases;
      for (int j = 0; j < n; j++) {
        string tmp(temp);
        tmp[r[i][j]] = 'Q';
        cases.push_back(tmp);
      }
      s.push_back(cases);
    }
    return s;
  }
};
int main() {
  Solution().solveNQueens(4);
  return 0;
}