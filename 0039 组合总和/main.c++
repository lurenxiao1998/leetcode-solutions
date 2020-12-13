#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> ans;
    sort(candidates.begin(), candidates.end());
    _combinationSum(result,ans,target,candidates,candidates.size()-1);
    return result;
  }
  void _combinationSum(vector<vector<int>> &r, vector<int> ans,
                       int less, vector<int> &candidates, int idx) {

    if (less == 0) {
      r.push_back(ans);
      return;
    }
    if (idx == -1)
      return;

    _combinationSum(r, ans, less, candidates,
                    idx - 1);
    for (int i = 1; i <= less / candidates[idx]; i++) {
      ans.push_back(candidates[idx]);
      
    _combinationSum(r, ans, less - candidates[idx]*i, candidates,
                    idx - 1);
    }
  }
};
int main(int argc, char const *argv[])
{
  vector<int> candidates={2,3,6,7};
  int target =7;
  Solution().combinationSum(candidates,target);
  return 0;
}
