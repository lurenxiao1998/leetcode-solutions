class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> mergeInterval(newInterval);
        for(int i=0;i< intervals.size();i++){
            if( newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }else if(newInterval[1] < intervals[i][0]){
                if(mergeInterval.size()!=0){
                    ans.push_back(mergeInterval);
                    mergeInterval={};
                }
                ans.push_back(intervals[i]);
            }else{
                mergeInterval[0]=min(mergeInterval[0],intervals[i][0]);
                mergeInterval[1]=max(mergeInterval[1],intervals[i][1]);
            }
        }
        if(mergeInterval.size()!=0){
            ans.push_back(mergeInterval);
        }
        return ans;

    }
};