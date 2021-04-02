class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> ans;
        int size = 1 << nums.size();
        for(int mask =0;mask<size;mask++){
            t.clear();
            for(int j=0;j<nums.size();j++){
                if(1<<j & mask){
                    t.push_back(nums[j]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};