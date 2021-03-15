#include <vector>
using namespace std;
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> r;
    if (matrix.size() == 0) {
      return r;
    }
    int width = matrix.size(), length = matrix[0].size();
    int terns = min(width, length) / 2;
    for (int tern = 0; tern < terns; tern++) {
      for (int j = tern; j <= length - tern - 1; ++j) {
        int i = tern;
        r.push_back(matrix[i][j]);
      }
      if( tern+1 == width-tern){
        break;
      }
      for (int i = tern+1; i <= width - tern - 1; ++i) {
        int j = length - tern-1;
        r.push_back(matrix[i][j]);
      }
      if( tern+1 == length-tern){
        break;
      }
      for (int j = length-tern-2; j >=tern ; --j)
      {
        int i = width-tern -1;
        r.push_back(matrix[i][j]);
      }
      for (int i = width-tern-2; i >tern ; --i)
      {
        int j = tern;
        r.push_back(matrix[i][j]);
      }
    }
    
    return r;
  }
};