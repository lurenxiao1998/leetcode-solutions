class Solution {
double myPowPos(double x,int n){
    double res=1;
    if(!n)
        return res;
    if(n&1)
        res = x * myPowPos(x*x,n/2);
    else
        res = myPowPos(x*x,n/2);
    return res;
}
public:
    double myPow(double x, int n) {
        double res=1;
        if(n<0){
            res=1/myPowPos(x,n);
        }else{
            res=myPowPos(x,n);
        }
        return res;
    }
};