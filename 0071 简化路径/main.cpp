class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string res="";
        string word="";
        for(int i=0;i<=path.size();i++){
            if(path[i]!='/' && i<path.size())
                word.push_back(path[i]);
            else{
                if(word==".."){
                    if(stk.size())
                        stk.pop_back();
                }
                else if(word!="." && word !=""){
                    stk.push_back(word);
                }
                word="";
            }
        }

        for(int i=0;i<stk.size();i++){
            res+="/"+stk[i];
        }
        
        return res.size()>0?res:"/";
    }
};