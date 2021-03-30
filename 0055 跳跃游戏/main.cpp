class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjmp=0;
        for(int i=0;i<nums.size();i++){
            if(maxjmp >= i){
                maxjmp=max(maxjmp,nums[i]+i);
            }else{
                return false;
            }
        }
        return true;
    }
};