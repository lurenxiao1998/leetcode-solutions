#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int idx = 0;
    for (idx = 0; idx < nums.size(); idx++) {
      if (target<=nums[idx]) {
        break;
      }
    }
    nums.insert(nums.begin() + idx, target);
    lower_bound(nums.begin(),nums.end(),target);
    return idx;
  }
};