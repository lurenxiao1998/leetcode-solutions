class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = 1 << nums.size();
        sort(nums.begin(),nums.end());
        vector<int> t{};
        vector<vector<int>> ans;
        for(int mask=0;mask<size;mask++){
            t={};
            int flag=true;
            for(int j=0;j<nums.size();j++){
                if(mask & 1 << j ){
                    if(j > 0 && nums[j]==nums[j-1] && (mask & 1<<(j-1)) == 0){
                        flag=false;
                        break;
                    }
                    t.push_back(nums[j]);
                }
            }
            if(flag)
                ans.push_back(t);
        }
        return ans;
    }
};