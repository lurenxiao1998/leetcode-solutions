class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char,string> dict{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        if(digits.size()==0){
            return res;
        }
        char num=digits[0];
        string s=dict[num];
        for(int i=0;i<s.size();i++){
            res.push_back(string(1,s[i]));
        }
        for(int i=1;i<digits.size();i++){
            vector<string> tmp;
            s=dict[digits[i]];

            for( int j=0;j<res.size();j++){
                for(int k=0;k<s.size();k++){
                    tmp.push_back( res[j] + s[k] );
                }
            }
            res= move(tmp);
        }
        return res;
    }
};