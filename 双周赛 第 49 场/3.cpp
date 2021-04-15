#include <bits/stdc++.h>
using namespace std;
class Solution {
    inline int rev(int num){
        int res=0;
        while(num){
            res=res*10+num%10;
            num/=10;
        }
        return res;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> zmap;
        long ans=0;
        for(int i=0;i<nums.size();i++){
            zmap[nums[i]-rev(nums[i])]++;
        }
        for(auto &&itor:zmap){
            ans+=long(itor.second-1)*itor.second/2;
        }
    }
};