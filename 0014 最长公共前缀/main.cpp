class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string res=strs[0];
        string s;
        for(int i=1;i<strs.size();i++){
            s=strs[i];
            int j=0;
            for(;j < res.size();j++){
                if( j >= s.size() || s[j] != res[j]){
                    break;
                }
            }
            res=res.substr(0,j);
            if(res == ""){
                return "";
            }
        }
        return res;
    }
};