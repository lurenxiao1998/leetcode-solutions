class Solution {
public:
    int countArrangement(int n) {
        vector<int> jl(1<<n,0);
        jl[0]=1;
        for(int mask=1;mask < (1<<n);mask++){
            int num = __builtin_popcount(mask);
            for(int i = 0;i <n ;i++){
                if( mask & (1<<i) &&( (num% (i+1)==0)|| (i+1)%num==0) ){
                    jl[mask] += jl[mask ^ (1<<i)];
                }
            }
        }
        return jl[(1<<n) -1];
    }
};