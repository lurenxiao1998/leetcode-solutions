class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> pal(s.size(),vector<bool>(s.size(),true));
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1])
                pal[i][i+1]=false;
        }
        for(int i=2;i<s.size();i++){
            for(int j=0;j<s.size()-i;j++){
                if(s[j]!=s[j+i] || ! pal[j+1][j+i-1])
                    pal[j][j+i]=false;
            }
        }
        int li=0;
        int maxlength=1;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(pal[i][j]){
                    int length=j-i+1;
                    if( length >maxlength){
                        li=i;
                        maxlength=length;
                    }
                }
            }
        }
        string res = s.substr(li,maxlength);
        return res;
        
    }
};