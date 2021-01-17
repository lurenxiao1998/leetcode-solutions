#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
      map<int,vector<pair<int, int>>> t;
      sort(nums.begin(),nums.end());
      int sum=0;
      for (size_t i = 0; i < nums.size(); i++)
      {
        for (size_t j = i+1; j < nums.size(); j++)
        {
          // auto tmp=t.find(nums[i]* nums[j]);
          // if( tmp ==t.end() ){
          //   vector<pair<int, int>> tmpvector{pair<int, int>(nums[i],nums[j])};
          //   t[nums[i]* nums[j]] = tmpvector;
          // }else{
          t[nums[i]* nums[j]].push_back(pair<int, int>(nums[i],nums[j]));
          // }
        }
        
      }
      for (auto iter = t.begin(); iter != t.end(); iter++)
      {
        int tmp=iter->second.size();
        sum += tmp*(tmp-1)*2;
      }
      return sum;
      
    }
};
int main(int argc, char const *argv[])
{
  vector<int>a{2,3,4,6};
  Solution().tupleSameProduct(a);
  return 0;
}
