class Solution {
public:
    int mySqrt(int x) {
        if(x==1)
            return 1;

        int left=0,right=x/2;
        while(right>left){
            mid=(left+right) >> 1;
            if( mid * mid >x)
                right = mid;
            else
                left=mid+1;
        }
        
        return mid*mid>x?mid-1:mid;
    }
};