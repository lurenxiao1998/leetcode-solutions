class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)
            return res;

        int li=0,ri=0;
        int num=0;
        sort(nums.begin(),nums.end());
        for(int i =0; i<nums.size()-3;i++){
            if(i>0 && nums[i]== nums[i-1])
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                continue;
            ri=nums.size()-1;
            if(nums[i] +nums[ri-2]+nums[ri-1] + nums[ri] <target)
                continue;
            
            for(int j =i+1;j < nums.size()-2;j++){
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                
                li=j+1;
                ri=nums.size()-1;
                if(nums[i] + nums[j] + nums[li] + nums[li+1] > target)
                    continue;
                if(nums[i] +nums[j]+nums[ri-1] + nums[ri] <target)
                    continue;

                while(ri>li){
                    num = nums[i] +nums[j]+nums[li]+nums[ri];
                    if( num < target || (li>j+1 && nums[li] == nums[li-1]))
                        li++;
                    else if(num > target || (ri < nums.size() -1 && nums[ri]  == nums[ri+1]))
                        ri--;
                    else{
                        res.push_back({nums[i],nums[j],nums[li],nums[ri]});
                        li++;
                    }
                }
            }
        }
        return res;
    }
};