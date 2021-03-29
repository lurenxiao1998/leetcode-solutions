class Solution {
    int gcd(int a,int b)
    {
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return gcd(b,a%b);
    }
    }
    int lcm(int a,int b)
    {
        return (a*b)/gcd(a,b);
    }
public:
    int reinitializePermutation(int n) {
        vector<int> repeat;
        int tern=0;
        int idx=-1;
        int res=1;
        for(int i =0;i<n;i++){
            tern=0;
            int ci=i;
            idx=-1;
            while(idx!=i){
                if(idx!=-1)
                    ci=idx;   
                tern++;
                
                if( ci & 0x1 ){
                    idx = n / 2 + (ci - 1) / 2;
                }else{
                    idx = ci/2;
                }
            }
            repeat.push_back(tern);
        } 
        for(int i=0;i<repeat.size();i++){
            res=lcm(res,repeat[i]);
        }
        return res;
        
    }
};