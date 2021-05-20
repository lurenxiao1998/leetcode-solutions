class Solution {
    int findTarget(vector<int>& nums,int idx, int target) {
        if(idx == nums.size()-1)
            return (target-nums[idx]==0)+(target + nums[idx]==0);
        
        return findTarget(nums,idx+1,target-nums[idx])+findTarget(nums,idx+1,target+nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTarget(nums,0,target);
    }
};