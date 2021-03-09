#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int subMaximumScore(vector<int> &nums, vector<int> &multipliers, int tern,
                      int m,int l,int r) {
    if (tern > m) {
      return 0;
    }
    int removeF = nums[l] * multipliers[tern-1];
    int removeL = nums[r] * multipliers[tern-1];
    removeF += subMaximumScore(nums, multipliers, tern + 1,m,l+1,r);
    removeL += subMaximumScore(nums, multipliers, tern + 1,m,l,r-1);
    return max(removeF, removeL);
  }
  int maximumScore(vector<int> &nums, vector<int> &multipliers) {
    return subMaximumScore(nums,multipliers,1,multipliers.size(),0,nums.size()-1);
  }
};
int main(int argc, char const *argv[])
{
  vector<int> nums{1,2,3};
  vector<int> multipliers{3,2,1};
  Solution().maximumScore(nums,multipliers);
  return 0;
}
