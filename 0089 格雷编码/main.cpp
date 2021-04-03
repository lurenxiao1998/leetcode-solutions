class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans{0,1};
        for(int i=1;i<n;i++){
            for(int j=ans.size()-1;j>=0;j--){
                ans.push_back( 1<<i | ans[j] );
            }
        }
        return ans;
    }
};