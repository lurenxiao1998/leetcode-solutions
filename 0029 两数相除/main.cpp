class Solution {
public:
    int divide(int dividend, int divisor) {
        int pos = (dividend>>31) ^ ( divisor >>31);
        int res=0;
        int negdividend = dividend>0?-dividend:dividend;
        int negdivisor = divisor>0?-divisor:divisor;
        int t=-1;
        int tmpdivisor = negdivisor;
        while( negdividend <= negdivisor ){
            t=-1;
            tmpdivisor = negdivisor;
            while( tmpdivisor >= INT_MIN/2 && tmpdivisor + tmpdivisor>negdividend ){
                t=t+t;
                tmpdivisor += tmpdivisor;
            }
            negdividend -= tmpdivisor;
            res += t;
        }
        return pos==0?res<-INT_MAX?INT_MAX:-res:res;
    }
};