class Solution {
public:
    int countDigitOne(int n) {
        long res=0;
        for(long num = 1 ; num<=n; num*=10 ){
            res += n/(num*10) * num + min(max(n%(num*10) - num + 1, 0l), num); 
        }
        return res;
    }
};