#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  void maxHeapify(vector<int> &nums, int i, int length) {
    int max = i;
    for (; i * 2 + 1 < length; ) {
      max = i;
      if (i * 2 + 1 < length && nums[i * 2 + 1] > nums[max]) {
        max = i * 2 + 1;
      }
      if (i * 2 + 2 < length && nums[i * 2 + 2] > nums[max]) {
        max = i * 2 + 2;
      }
      if (max == i)
        break;
      swap(nums[max], nums[i]);
      i = max;
    }
  }
  void buildHeap(vector<int> &nums, int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
      maxHeapify(nums, i, length);
    }
  }
  void heapSort(vector<int> &nums) {
    int length = nums.size();
    buildHeap(nums, length);
    for (int i = length - 1; i >= 0; i--) {
      swap(nums[i], nums[0]);
      maxHeapify(nums, 0, i);
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    heapSort(nums);
    return nums;
  }
};
int main(){
    vector<int> test{-4,0,7,4,9,-5,-1,0,-7,-1};
    Solution().sortArray(test);
}