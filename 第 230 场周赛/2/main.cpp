#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                  int target) {
    set<int> costs;
    int closeCost=INT32_MAX;
    int ternclose = 0;
    for (size_t i = 0; i < int(pow(3,toppingCosts.size())); i++) {
      int cost = 0;
      int num = i, idx = 0;
      while (num) {
        cost += toppingCosts[idx] * (num % 3);
        idx++;
        num /= 3;
      }
      costs.insert(cost);
    }
    
    for (size_t i = 0; i < baseCosts.size(); i++) {
      auto t = costs.upper_bound(target - baseCosts[i]);

      if (t == costs.begin()) {
        int costb = baseCosts[i] + *t;
        ternclose = costb;
      } else {
        int costb = baseCosts[i] + *t;
        int costa = baseCosts[i] + *(--t);
        if (abs(target - costb) == abs(target - costa)) {
          ternclose = costa;
        } else {
          ternclose = abs(target - costb) < abs(target - costa) ? costb : costa;
        }
      }
      if ((abs(target - ternclose) < abs(target - closeCost) ||
           (abs(target - ternclose) == abs(target - closeCost) &&
            ternclose < closeCost))) {
        closeCost = ternclose;
      }
    }
    return closeCost;
  }
};
int main(int argc, char const *argv[])
{
  Solution().closestCost()
  return 0;
}
