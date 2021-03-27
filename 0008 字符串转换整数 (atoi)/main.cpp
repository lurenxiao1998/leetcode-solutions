class Solution {
public:
    int myAtoi(string s) {
        int res=0;
        int i=0;
        while(s[i] == ' ')
            i++;
        int c=0;
        if(s[i] >= '0' && s[i]<='9' ||s[i]=='+'){
            if(s[i]=='+')
                i++;
            for(;i<s.size();i++){
                c=s[i]-'0';
                if(c>=0 && c<=9){
                    if( res > INT_MAX/10 || (res == INT_MAX/10 && c>=8)){
                        return INT_MAX;
                    }
                    res = res*10 + c;
                }else{
                    return res;
                }
            }
        }else if(s[i]=='-'){
            for(i++;i<s.size();i++){
                c=s[i]-'0';
                if(c>=0 && c<=9){
                    if( res < INT_MIN/10 || (res == INT_MIN/10 && c>=9)){
                        return INT_MIN;
                    }
                    res = res*10 - c;
                }else{
                    return res;
                }
            }
        }
        return res;
    }
};