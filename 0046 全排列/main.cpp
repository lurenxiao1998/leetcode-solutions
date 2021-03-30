class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int>& nums,int less,vector<int> &route){
        if(less==0){
            vector<int > tmp(route);
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                route.push_back(nums[i]);
                used[i]=true;
                dfs(nums,less-1,route);
                used[i]=false;
                route.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        used = vector<bool>(nums.size(),false);
        dfs(nums,nums.size(),tmp);
        return res;
    }
};