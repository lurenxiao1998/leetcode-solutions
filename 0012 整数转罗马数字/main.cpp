class Solution {
public:
    string intToRoman(int num) {
        vector<int> numtable{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> strtable{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        int n=0;
        for(int i =0;i<numtable.size();i++){
            n=num / numtable[i];
            if( n != 0 ){
              for(int j=0;j<n;j++){
                res.append(strtable[i]);
              }
              num=num%numtable[i];
            }
        }
        return res;
    }
};