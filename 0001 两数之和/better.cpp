class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            auto it = hashtable.find(target-nums[i]); 
            if( it != hashtable.end() ){
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
            hashtable[nums[i]]=i;
        }
        return res;
    }
};