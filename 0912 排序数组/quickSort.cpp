#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  void quickSort(vector<int> &nums, int start, int end) {
    if (start >= end)
      return;
    int i = start, j = end;
    int tmp = nums[start];
    while (i < j) {
      while (i < j && nums[j] >= tmp) {
        --j;
      }
      if (i == j) {
        break;
      }
      nums[i++] = nums[j];
      while (i < j && nums[i] < tmp) {
        ++i;
      }
      if (i == j) {
        break;
      }
      nums[j--] = nums[i];
    }
    nums[i] = tmp;
    quickSort(nums, i+1, end);
    quickSort(nums, start, i-1);
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
int main() {
  vector<int> a{5, 1, 1, 2, 0, 0};
  Solution().sortArray(a);
}