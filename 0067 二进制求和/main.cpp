class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int lena=a.size(),lenb = b.size();
        int binarya=0,binaryb=0;
        int carry=0,r=0;
        for(int i=0;i<lena || i< lenb || carry != 0;i++){
            binarya = i >= lena ? 0: a[lena-i-1]-'0';
            binaryb = i >= lenb ? 0: b[lenb-i-1]-'0';
            r = (binaryb^binarya)^carry;
            carry = (binaryb+binarya+carry)>>1;
            res.push_back(r+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    
    }
};