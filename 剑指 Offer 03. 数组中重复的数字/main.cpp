class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=i){
                int num=nums[i];
                while(nums[i]!=i){
                    if(nums[num]==nums[i]){

                        return num;
                    }
                    swap(nums[i],nums[num]);
                    num=nums[i];
                }
            }
        }
        return 0;
    }
};