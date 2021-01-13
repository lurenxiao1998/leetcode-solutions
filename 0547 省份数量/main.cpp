#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> ids;
  int findCircleNum(vector<vector<int>> &isConnected) {
    ids.resize(isConnected.size());
    set<int> S;
    iota(ids.begin(), ids.end(), 0);
    for (size_t i = 0; i < isConnected.size(); i++) {
      for (size_t j = i + 1; j < isConnected.size(); j++) {
        if (isConnected[i][j] == 1) {
          U(i, j);
        }
      }
    }
    for (size_t i = 0; i < isConnected.size(); i++) {
      S.insert(F(i));
    }
    return S.size();
  }
  int F(int x) { return x == ids[x] ? x : (x = F(ids[x])); }
  void U(int i, int j) { ids[F(i)] = ids[F(j)]; }
};
int main(){
  vector<vector<int>> isConnected(3,vector<int>(3,0));
  isConnected[0]={1,1,1};
  isConnected[1]={1,1,1};
  isConnected[2]={1,1,1};
  Solution().findCircleNum(isConnected);
}