class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,m=matrix.size(),n=matrix[0].size(),r=m*n-1,mid,i,j;
        while( r>l ){
            mid=(l+r)/2;
            i=mid/n;
            j=mid%n;
            if( matrix[i][j] < target){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        i=l/n;
        j=l%n;
        return matrix[i][j] ==target?true:false;
    }
};