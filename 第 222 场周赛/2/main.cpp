#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countPairs(vector<int> &deliciousness) {
    vector<long> d;
    map<long, long> num_idx;
    long sum = 0;
    for (int i = 0; i < 22; i++) {
      d.push_back(int(pow(2, i)));
    }
    for (int i = 0; i < deliciousness.size(); i++) {
      ++num_idx[deliciousness[i]];
    }

    auto iter = num_idx.begin();
    while (iter != num_idx.end()) {

      long num = iter->first;
      long numOfnum = iter->second;
      for (auto &&zhi : d) {

        auto theOther = num_idx.find(zhi - num);

        if (zhi - num < num) {
          continue;
        }
        if (theOther != num_idx.end()) {
          if (zhi - num == num) {
            sum += theOther->second * (theOther->second - 1) / 2;
          } else {
            sum += numOfnum * theOther->second;
          }
        }
      }

      iter++;
    }

    return sum%(int(pow(10, 9))+7);
  }
};

int main(int argc, char const *argv[]) {
  vector<int> deliciousness{1,1,1,3,3,3,7};
  cout << Solution().countPairs(deliciousness);

  return 0;
}
