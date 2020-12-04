#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ascending(int i,int j){return (i<j);}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tmp=0;
        for (int i = nums.size()-1; i > 0 ; i--)
        {
            if(nums[i-1]<nums[i]){
                auto a=nums.rbegin() +(nums.size()-i);
                auto b=*upper_bound(nums.rbegin(),nums.rbegin() +(nums.size()-i) ,nums[i-1]);
                auto c=* lower_bound(nums.begin()+1,nums.end(),nums[i-1]);
                swap(nums[i-1],*upper_bound(nums.rbegin(),nums.rbegin() +(nums.size()-i) ,nums[i-1]));
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end(),ascending);
    }
};

int main(){
    vector<int> b{1,5,1};
    auto c= * upper_bound(b.rbegin(),b.rbegin()+1,1);
    vector<int> a{1,2,3};
    Solution().nextPermutation(a);
    return 0;
}