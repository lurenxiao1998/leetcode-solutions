class Solution {
vector<vector<int>> res;
vector<int>path;
void recursion(vector<int>& nums,int k,int n){
    if(k>=n){
        res.push_back(path);
        return ;
    }
    path.push_back(nums[k]);
    recursion(nums,k+1,n);
    path.pop_back();
    recursion(nums,k+1,n);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        recursion(nums,0,nums.size());
        return res;
    }
};