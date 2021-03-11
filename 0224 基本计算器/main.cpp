#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        string sStack="";
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i]!=' '){
                if(s[i] !=')' ){
                    sStack.push_back(s[i]);
                }else{
                    int pos=sStack.rfind('(');
                    if( pos == -1)
                        return -1;
                    int tmp =calculateS(sStack.substr(pos+1));
                    if(pos!=0 && (tmp<0 && sStack[pos-1]=='-')){
                        tmp=-tmp;
                        sStack[pos-1]='+';
                    }
                    sStack.erase(pos);
                    sStack.append(to_string(tmp));
                }
            }
        }
        return calculateS(sStack);
        
        
    }
private:
    int calculateS(const string & subs){
        int pos=0;
        int tmp=0;
        int operate=1;
        while (pos <subs.length())
        {
            
            int tmppos = subs.find_first_of("+-",pos);
            int num = atoi(subs.substr(pos,tmppos-pos).c_str());
            tmp += operate * num;
            if(tmppos!=string::npos){
                if(subs[tmppos]=='-'){
                    operate = -1;
                }
                else{
                    operate = 1;
                }
                pos=tmppos+1;
            }
            else{
                break;
            }
        }
        return tmp;
        
    }
};
int main(){
    Solution().calculate("2-(5-6)");
}