class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1,idx=0;
        while(idx<=r){
            while(l < r &&  nums[l]==0){
                l++;
            }
            while(r > l && nums[r]==2){
                r--;
            }
            if(l==r){
                break;
            }
            idx=l;
            while(idx<=r){
                if(nums[idx]==2){
                    swap( nums[idx] , nums[r--] );
                    break;
                }
                if(nums[idx]==0){
                    swap(nums[idx],nums[l++]);
                    break;
                }
                idx++;
            }
        }
    }
};