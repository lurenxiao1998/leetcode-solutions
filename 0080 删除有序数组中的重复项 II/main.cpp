class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int f2num=nums[0];
        int lastnum=nums[1];
        int idx=2;
        for(int i=2;i<nums.size();i++){
            if( nums[i] != f2num){
                nums[idx++] = nums[i];
            }
            f2num=lastnum;
            lastnum=nums[i];
        }
        return idx;
    }
};