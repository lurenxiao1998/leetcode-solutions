#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                  int target) {
    set<int> costs;
    int closeCost;
    int ternclose = 0;
    for (size_t i = 0; i < 3 << (toppingCosts.size()-1); i++) {
      int cost = 0;
      int num = i, idx = 0;
      while (num) {
        cost += toppingCosts[idx] * num % 3;
        idx++;
        num /= 3;
      }
      costs.insert(cost);
    }
    for (auto &&i : costs)
    {
      cout<<i<<endl;
    }
    
    
    for (size_t i = 0; i < baseCosts.size(); i++) {
      auto t = upper_bound(costs.begin(), costs.end(), target - baseCosts[i]);
      if (t == costs.begin()) {
        int costb = baseCosts[i] + *t;
        ternclose = costb;
      } else {
        int costb = baseCosts[i] + *t;
        int costa = baseCosts[i] + *(--t);
        if (abs(target - costb) == abs(target - costa)) {
          closeCost = costa;
        } else {
          closeCost = abs(target - costb) < abs(target - costa) ? costb : costa;
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