class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string res="";
        int t=0;
        int idx=0;
        for(int i=0;i<numRows;i++){
            t=0;
            idx=i;
            if(i==0 || i== numRows -1){
                while( t* (2*numRows-2)+i <s.size()){
                    res.push_back(s[ t++ * (2*numRows-2) + i]);
                }
            }
            else{
                while( idx<s.size() ){
                    idx=t * (2*numRows-2) + i;
                    if(idx < s.size()){
                        res.push_back(s[idx]);
                    }
                    idx=++t * (2 * numRows-2) - i;
                    if(idx < s.size()){
                        res.push_back(s[idx]);
                    }
                }
            }
        }
        
        return res;
    }
};