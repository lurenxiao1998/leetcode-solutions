class Solution {
private:
int binarySearch(vector<int>& nums, int left ,int right,int target,bool eq){
    while(right>left){
        int mid = (left+right)/2;
        if( nums[mid] < target || eq && nums[mid] == target )
            left = mid+1;
        else
            right = mid;
    }
    return left;
}
public:
  vector<int> searchRange(vector<int> &nums, int target) {
      vector<int> res;
      if(nums.size()==0)
          return {-1,-1};
      
      int left=binarySearch(nums,0,nums.size()-1,target,false);
      int right=binarySearch(nums,0,nums.size()-1,target,true);
      if(nums[right]!=target)
        right--;
      if(nums[left] != target)
          return {-1,-1};
      else
          return {left,right};
  }
};