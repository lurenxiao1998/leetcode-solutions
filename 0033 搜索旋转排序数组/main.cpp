class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid = right/2;
        while( right > left){
            if( nums[right] < nums[left] ){
                if( nums[mid] >= nums[left] ){
                    if( target > nums[mid] || target <= nums[right]){
                        left=mid+1;
                    }else if(target <= nums[mid] && target >= nums[left] ){
                        right=mid;
                    }else{
                        return -1;
                    }
                }
                else{
                    if( target <= nums[mid] || target >= nums[left]){
                        right=mid;
                    }else if(target > nums[mid] && target <= nums[right] ){
                        left=mid+1;
                    }else{
                        return-1;
                    }
                }
            }else{
                if(nums[mid] < target){
                    left=mid + 1;
                }else{
                    right=mid;
                }
            }
            mid=(left+right)/2;
        }
        if(nums[left]==target)
            return mid;
        return -1;
    }
};