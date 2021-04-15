#include <bits/stdc++.h>
using namespace std;
class Solution {
  int ans;
  vector<int> path;
  int dfs(vector<int>& z,int size,int batchSize){
    int res=0;
    if(path.size()==size){
      int sum=0;
      for(int i=0;i<size;i++){
        sum+=path[i];
        if(sum%batchSize==0){
          res++;
        }
      }
      if(sum%batchSize!=0)
        res++;
      return res;
    }
    for(int i=0;i<z.size();i++){
      if(z[i]){
        z[i]--;
        path.push_back(i);
        res=max(dfs(z,size,batchSize),res);
        path.pop_back();
        z[i]++;
      }
    }
    return res;
  }
public:
    int maxHappyGroups(int batchSize, vector<int> groups) {
        vector<int> z(batchSize,0);
        for(int i=0;i<groups.size();i++){
            z[groups[i]%batchSize]++;
        }
        ans+=z[0];
        z[0]=0;
        int tmp=0;
        for(int i=1;i<=(batchSize/2);i++){
          if(i==batchSize-i){
            ans+=z[i]/2;
            z[i]=z[i]%2;
          }
          else{
            tmp=min(z[i],z[batchSize-i]);
            z[batchSize-i]-=tmp;
            z[i]-=tmp;
            ans+=tmp;
          }
        }
        ans+=dfs(z,accumulate(z.begin(),z.end(),0),batchSize);
        return ans;
    }
};
int main(int argc, char const *argv[])
{


  Solution().maxHappyGroups(7,{913755180,410548740,861904937,970046203,464846019,426533182,176903496,977195438,349467825,470437382,135645883,668299648,975907584,523950062,227649515,127975782,463062439,644974251,573436699,438327287,976349192,126798202});
  return 0;
}
