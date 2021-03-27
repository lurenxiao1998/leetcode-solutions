#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<int>& mergeSort(vector<int> &nums, int start, int end) {
    if (start >= end) {
      
    }
    int mid = (end + start) >> 1;
    auto nums1 = mergeSort(nums, start, mid);
    auto nums2 = mergeSort(nums, mid + 1, end);
    int i = start, j = mid + 1;
    vector<int> res;
    while (i <= mid && j <= end) {
      if (nums1[i] < nums2[j]) {
        res.push_back(nums1[i++]);
      } else {
        res.push_back(nums2[j++]);
      }
    }
    if(i==mid){
      res.emplace_back(nums2.begin()+j,nums2.end());
    }else{
      res.emplace_back(nums1.begin()+i,nums1.end());
    }
    return res;
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    nums=mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
int main() {
  vector<int> a{5, 1, 1, 2, 0, 0};
  Solution().sortArray(a);
}