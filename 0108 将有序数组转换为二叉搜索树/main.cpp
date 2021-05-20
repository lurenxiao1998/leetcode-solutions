class Solution {
    TreeNode* buildBST(vector<int>& nums,int left,int right){
        if(right<left)
            return nullptr;
        
        return new TreeNode(nums[(right+left)>>1],buildBST(nums,left,((right+left)>>1)-1),buildBST(nums,((right+left)>>1)+1,right));
    }
public:
    TreeNode* sortedArrayToBST(vector<int> nums) {
        return buildBST(nums,0,nums.size()-1);
    }
};