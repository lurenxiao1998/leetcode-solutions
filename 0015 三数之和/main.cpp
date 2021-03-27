class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int target=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i] ==nums[i-1])
                continue;
            target=-nums[i];
            int li=i+1;
            int ri=nums.size()-1;
            while(ri>li){
                if(target > nums[li]+nums[ri] || (li > i+1 && nums[li]==nums[li-1])){
                    li++;
                }else if(target < nums[li] + nums[ri] || ( ri < nums.size()-1 && nums[ri] == nums[ri+1] )){
                    ri--;
                }else{
                    vector<int> tmp={ nums[i] , nums[li], nums[ri] };
                    res.push_back(tmp);
                    li++;
                }
            }
        }
        return res;
    }
};