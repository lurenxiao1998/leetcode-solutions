class Solution {
private:
int binarySearch(vector<int>& nums, int left ,int right,int target){
    if(right<left)
        return -1;
    int mid=(right+left)/2;
    while(right>left){
        if( nums[mid] < target )
            left = mid+1;
        else
            right = mid;
        
        mid = (left+right)/2;
    }
    if(nums[left]!=target)
        return -1;
    return left;
}
public:
  vector<int> searchRange(vector<int> &nums, int target) {
      vector<int> res;
      int left,right;
      int idx=binarySearch(nums,0,nums.size()-1,target);
      left=right=idx;
      if(idx==-1){
          return {left,right};
      }
      while(left > 0){
          if( nums[left-1] == target ){
              idx=binarySearch(nums,0,left-1,target);
              if( idx == -1 ){
                  break;
              }
              left=idx;
          }else{
              break;
          }
      }
      while(right < nums.size() - 1 ){
          if(nums[right+1] == target){
              idx = binarySearch(nums,right+1,nums.size()-1,target);
                if(idx==-1){
                    break;
                }
                right=idx;
          }
          else{
              break;
          }
      }
      return {left,right};
  }
};