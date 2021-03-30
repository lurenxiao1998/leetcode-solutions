class Solution {
public:
    int lengthOfLastWord(string s) {
        bool split=true;
        int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i] <= 'z'&&s[i]>='A'){
                if(split)
                    len=1;
                else
                    len++;
                split=false;
            }else
                split=true;
        }
        return len;
    }
};