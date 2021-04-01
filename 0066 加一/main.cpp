class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i >= 0; i--){
            digits[i]++;
            digits[i] = digits[i] % 10;
            if(digits[i]!=0)
                break;
        }
        if(digits[0]==0){
            vector<int> res(digits.size()+1,0);
            res[0]=1;
            return res;
        }
        else
            return digits;
        
    }
};