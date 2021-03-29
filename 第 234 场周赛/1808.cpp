#define LL long long
class Solution {
LL quickPow(LL a,LL b,LL mod)
{
    int res = 1;
    while(b)
    {
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res%mod;//这里%是要注意这种情况a = 1 b = 0 mod = 1
}
public:
    int maxNiceDivisors(int primeFactors) {
        int res;
        if(primeFactors==1)
            return 1;
        if(primeFactors%3==0)
            res = quickPow(3,primeFactors/3,1000000007);
        else if((primeFactors-4)%3==0){
            res = quickPow(3,(primeFactors-4)/3,1000000007);
            res = (res*2)%1000000007;
            res = (res*2)%1000000007;
        }
        else if((primeFactors-2)%3==0){
            res = quickPow(3,primeFactors/3,1000000007);
            res = (res*(primeFactors%3))%1000000007;
        }
        // int res = quickPow(3,primeFactors/3);
        
        return res;
    }
};