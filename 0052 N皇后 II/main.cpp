class Solution {
  int caseNum=0;
  vector<int> case1;
  void solveNQueens(int queenNum, int n) {
    if (queenNum == n) {
      ++caseNum;
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
    return caseNum;
  }
};