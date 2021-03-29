class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> hashtable;
        string word="";
        string res="";
        for(int i =0;i<knowledge.size();i++){
            hashtable[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                res += word;
                word="";
            }else if( s[i]==')'){
                auto tword=hashtable.find(word);
                if(tword !=hashtable.end() ){
                    res.append(hashtable[word]);
                }else{
                    res+="?";
                }
                word="";
            }else{
                word += s[i];
                if(i==s.size()-1){
                    res+=word;
                }
            }
        }
        return res;
    }
};