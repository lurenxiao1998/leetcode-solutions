class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int li,ri;
        int numli,numri;
        int res=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            li=i+1;
            ri=nums.size()-1;
            while(ri>li){
                numli = nums[li];
                numri = nums[ri];
                int sum=numri + numli + nums[i];
                if( abs( sum - target) < abs( res  -target ) ){
                    res=sum;
                }
                if( sum > target){
                    ri--;
                }else{
                    li++;
                }
            }
        }
        return res;
    }
};