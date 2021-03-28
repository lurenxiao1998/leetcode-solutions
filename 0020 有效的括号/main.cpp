class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> leftPool={'{','(','['};
        unordered_map<char,char> rightPool={{'}','{'},{')','('},{']','['}};
        string stk;
        for(int i =0;i<s.size();i++){
            if( leftPool.find(s[i]) != leftPool.end() ){
                stk.push_back(s[i]);
            }else{
                if( stk.size() >0 && stk.back() == rightPool[ s[i] ]){
                    stk.pop_back();
                }else{
                    return false;
                }
            }
        }
        return stk.size()==0;
    }
};