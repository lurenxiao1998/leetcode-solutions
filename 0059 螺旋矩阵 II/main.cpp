#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> r(n, vector<int>(n, 0));
    int terns = (n + 1) / 2;
    int idx = 0;
    int left = 0;
    int right = n - 1;
    int bottom = n - 1;
    int top = 0;
    for (int tern = 0; tern < terns; tern++) {
      for (int j = left; j <= right; j++) {
        r[top][j] = ++idx;
      }
      ++top;
      for (int i = top; i <= bottom; i++) {
        r[i][right] = ++idx;
      }
      --right;
      for (int j = right; j >= left; j--) {
        r[bottom][j] = ++idx;
      }
      --bottom;
      for (int i = bottom; i >= top; i--) {
        r[i][left] = ++idx;
      }
      ++left;
    }
    return r;
  }
};
int main(){
  Solution().generateMatrix(3);
  return 0;
}