#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> mem;
    int dfs(int left,int right){
        cout<<" "<<left<<" "<<right<<endl;
        if(mem[right-left+1]){
            return mem[right-left+1];
        }

        int res=0;
        for(int i=left;i<=right;i++){
            res += dfs(left,i-1)*dfs(i+1,right);
        }
        mem[right-left+1]=res;
        return res;
    }
public:
    int numTrees(int n) {
        if(n==0){
            return 0;
        }
        mem=vector<int>(n,0);
        mem[0]=1;
        mem[1]=1;
        return dfs(1,n);
    }
};