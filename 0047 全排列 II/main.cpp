class Solution {
vector<vector<int>> res;
vector<bool> vis;
void revursion(vector<int>& nums,int less,vector<int>& route){
    if(less ==0){
        res.push_back(route);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!vis[i]){
            if( i != 0 && !vis[i-1] && nums[i] == nums[i-1]){
                continue;
            }
            vis[i] = true;
            route.push_back(nums[i]);
            revursion(nums,less-1,route);
            route.pop_back();
            vis[i] = false;
        }
    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis = vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        vector<int> route;
        revursion(nums,nums.size(),route);
        return res;
    }
};