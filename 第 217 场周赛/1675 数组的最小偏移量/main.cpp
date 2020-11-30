#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minimumDeviation(vector<int> &nums) {
    for (auto &&num : nums) {
      if (num % 2 == 1)
        num *= 2;
    }
    priority_queue<int, vector<int>, less<int>> q{nums.begin(), nums.end()};
    int a = *min_element(nums.begin(), nums.end());
    int bound = q.top() - a;
    auto max_e = 0;
    while (!q.empty()) {
      max_e = q.top();
      q.pop();
      if (max_e % 2 == 1)
        return bound;
      if (max_e / 2 < a) 
        a = max_e / 2;
      q.push(max_e / 2);
      bound = min(q.top() - a, bound);
    }
    return bound;
  }
};