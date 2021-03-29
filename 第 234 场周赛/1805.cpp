class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> hashtable;
        string num="";
        for(int i=0;i<word.size();i++){
            if(word[i] >= '0' && word[i] <='9'){
                if(word[i]=='0' && num==""){
                    num="0";
                }else{
                    if(num=="0")
                        num=word[i];    
                    else
                        num+=word[i];
                    
                }
            }else{
                if( num!="" ){
                    hashtable.emplace(num);
                }
                num="";
            }
        }
        if(num != ""){
            hashtable.emplace(num);
        }
        return hashtable.size();
    }
};