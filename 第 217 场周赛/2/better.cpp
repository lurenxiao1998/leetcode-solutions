#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> m{nums[0]};
    int less = k;
    for (int i = 1; i < nums.size(); i++) {
      auto insert_idx = upper_bound(m.end() - min(m.size(), nums.size() - i), m.end(), nums[i]);
      printf("%d",insert_idx-m.begin());
      if(insert_idx-m.begin()<k+1){
        m.erase(insert_idx, m.end());
        m.insert(insert_idx, nums[i]);
      }
    }
    if (m.size() > k)
      m.pop_back();
    return m;
  }
};

int main() {
  vector<int> a{71,18,52,29,55,73,24,42,66,8,80,2};
  Solution().mostCompetitive(a, 2);
  return 0;
}