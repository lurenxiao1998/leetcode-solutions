#include <vector>
using namespace std;
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int flag_col0 = false;
    for (int i = 0; i < m; i++) {
      if (!matrix[i][0]) {
        flag_col0 = true;
      }
      for (int j = 1; j < n; j++) {
        if (!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 1; j < n; j++) {
            if (!matrix[i][0] || !matrix[0][j]) {
                matrix[i][j] = 0;
            }
        }
        if (flag_col0) {
            matrix[i][0] = 0;
        }
    }
  }
};
int main(){
  vector<vector<int>> test={{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
  Solution().setZeroes(test);
}