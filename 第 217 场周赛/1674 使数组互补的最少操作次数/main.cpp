#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minMoves(vector<int> &nums, int limit) {
    int *acc;
    auto n = nums.size();
    acc = (int *)calloc((2 * limit + 2),sizeof(int));
    acc[1] = n;
    for (int i = 0; i < n / 2; i++) {
      int a = nums[i];
      int b = nums[n - i-1];
      acc[min(a + 1, b + 1)] -= 1;
      acc[a + b] -= 1;
      acc[a + b + 1] += 1;
      acc[max(a + limit, b + limit) + 1] += 1;
    }
    for (int i = 1; i < 2 * limit; i++) {
      acc[i + 1] = acc[i + 1] + acc[i];
    }
    int minChange = n;
    for (int i = 1; i < 2 * limit+1 ; i++) {
      if (acc[i] < minChange)
        minChange = acc[i];
    }

    return minChange;
  }
};
int main(){
    vector<int> a{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution().minMoves(a,1);
    return 0;

}