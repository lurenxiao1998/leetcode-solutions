class Solution {
public:
    int climbStairs(int n) {
        int p=0,q=1,m=0;
        for(int i=1;i<=n;i++){
            m=p+q;
            p=q;
            q=m;
        }
        return m;
    }
};