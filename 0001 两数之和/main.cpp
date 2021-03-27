class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums_copy;
        for(int i=0;i<nums.size();i++){
            nums_copy.push_back( pair<int,int>{nums[i],i});
        }

        sort(nums_copy.begin(),nums_copy.end());
        
        
        vector<int> res;
        int li=0,ri=nums.size()-1;
        int h;
        while(ri>li){
            h=nums_copy[ri].first + nums_copy[li].first;
            if( h > target ){
                ri--;
            }
            if(h<target){
                li++;
            }
            if(h==target){
                res.push_back(nums_copy[li].second);
                res.push_back(nums_copy[ri].second);
                return res;
            }
        }
        return res;
    }
};