#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int stoneGameVII(vector<int> &stones) {
    vector<vector<int>> a(stones.size(), vector<int>(stones.size(), 0));
    vector<vector<int>> acc(stones.size(), vector<int>(stones.size(), 0));
    bool alice_tern = false;
    if (stones.size() % 2 == 0) {
      alice_tern = true;
    }
    for (size_t i = 0; i < stones.size(); i++) {
      for (size_t j = i; j < stones.size(); j++) {
        if (j == 0) {
          acc[i][j] = stones[j];
        } else {
          acc[i][j] = acc[i][j - 1] + stones[j];
        }
      }
    }

    int tern = 1;
    while (tern < stones.size()) {
      if (alice_tern) {

        for (size_t i = 0; i < stones.size() - tern; i++) {
          a[i][i + tern] = max(a[i + 1][i + tern] + acc[i + 1][i + tern],a[i][i + tern - 1] + acc[i][i + tern - 1]);
        }
        alice_tern=!alice_tern;
      } else {
        for (size_t i = 0; i < stones.size() - tern; i++) {
          a[i][i + tern] = min(a[i + 1][i + tern] - acc[i + 1][i + tern],a[i][i + tern - 1] - acc[i][i + tern - 1]);
        }
        alice_tern=!alice_tern;
      }
      tern += 1;
    }
    return a[0][stones.size()-1];
  }
};
int main(int argc, char const *argv[])
{
  vector<int> test{5,3,1,4,2};
  Solution().stoneGameVII(test);
  return 0;
}
