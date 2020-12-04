#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    
    vector<int> r{
        int(lower_bound(nums.begin(), nums.end(), target) - nums.begin()),
        int(nums.size() - 1 - (lower_bound(nums.rbegin(), nums.rend(), target, greater<int>())-nums.rbegin()))};
    if(r[0]>r[1]){
        return {-1,-1};
    }
    return r;
  }
};

int main(){
    vector<int> a={8};
    Solution().searchRange(a,8);
    return 0;
}
