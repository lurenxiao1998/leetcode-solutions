#include <bits/stdc++.h>
using namespace std;


bool compare(vector<int> a, vector<int> b) {
  return a[1] > b[1]; //升序排列，如果改为return a>b，则为降序
}
class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), compare);
    int truckSizeLess = truckSize;
    int num = 0;
    for (auto &&box : boxTypes) {
      if (box[0] <= truckSizeLess) {
        num += box[1] * box[0];
        truckSizeLess -= box[0];
      } else {
        num += box[1] * truckSizeLess;
        return num;
      }
    }
  }
};
int main(int argc, char const *argv[])
{
  vector<vector<int>> boxTypes;
  boxTypes.push_back(vector<int>{1,3});
  boxTypes.push_back(vector<int>{2,2});
  boxTypes.push_back(vector<int>{3,1});
  Solution().maximumUnits(boxTypes,4);
  return 0;
}
