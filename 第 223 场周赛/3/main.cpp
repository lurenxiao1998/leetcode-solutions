#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
      vector<int> graph(source.size(),0);
      int graphidx=1;
      for (size_t i = 0; i < allowedSwaps.size(); i++)
      {
        if( graph[allowedSwaps[i][0]] ==0){
          if(graph[allowedSwaps[i][1]] ==0){
            graph[allowedSwaps[i][0]] =graphidx;
            graph[allowedSwaps[i][1]] =graphidx;
          }
          else{
            graph[allowedSwaps[i][0]] =graph[allowedSwaps[i][1]];
          }
        }
        else{
          if(graph[allowedSwaps[i][1]] ==0){
            graph[allowedSwaps[i][0]] =graphidx;
            graph[allowedSwaps[i][1]] =graphidx;
          }
        }
        allowedSwaps[i];
      }
      
    }
};