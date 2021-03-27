class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        int max_length=0;
        int idx=0;
        vector<int> position(256,-1);
        for(int i=0;i<s.size();i++){
            idx=position[ s[i] ];
            if(i - idx <= length){
                length = i - idx;
            }
            else{
                length++;
            }
            position[ s[i] ] = i;
            if(length > max_length){
                max_length=length;
            }
        }
        return max_length;
    }
};