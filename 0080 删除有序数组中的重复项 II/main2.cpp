class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int idx=1;
        for(int i=1;i<nums.size();i++){
            if( nums[i] == nums[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            if(count <= 2)
                nums[idx++]=nums[i];
        }
        return idx;
    }
};