#include<vector>
#include<algorithm>
using namespace std;
int comp(int a,int b){
  return a>b;
}
class Solution {
private:
    vector<vector<int>> combinationSums;
    void combinationSum(vector<int> &sum,vector<int>& candidates, int idx,int target) {
      if(target == 0){
        combinationSums.push_back(vector<int>(sum));
      }
      for (int i = idx; i < candidates.size(); i++)
      {
        if(i>idx && candidates[i]==candidates[i-1]){
          continue;
        }
        if(target-candidates[i]>=0){
          sum.push_back(candidates[i]);
          combinationSum(sum,candidates,i+1,target-candidates[i]);
          sum.pop_back();
        }
      }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end(),comp);
      vector<int> sum;
      combinationSum(sum,candidates,0,target);
      return combinationSums;
    }
};