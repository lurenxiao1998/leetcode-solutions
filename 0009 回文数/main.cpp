class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int y=0;
        int cx=x;
        while(cx){
            if(y > INT_MAX/10){
                return false;
            }
            y=y*10+cx%10;
            cx/=10;
        }
        return y==x;
    }
};