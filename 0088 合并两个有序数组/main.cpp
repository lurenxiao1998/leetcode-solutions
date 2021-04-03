class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num2i=n-1,num1i=m-1;
        int tmpnum1,tmpnum2;
        for(int i=m+n-1;i>=0;i--){
            tmpnum1 = num1i >= 0 ? nums1[num1i]: INT_MIN;
            tmpnum2 = num2i >= 0 ? nums2[num2i] : INT_MIN;
            if(tmpnum2>tmpnum1){
                nums1[i] = tmpnum2;
                num2i--;
            }else{
                nums1[i] = tmpnum1;
                num1i--;
            }
        }
    }
};