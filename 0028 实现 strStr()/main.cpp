#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle==""){
            return 0;
        }
        unsigned int ssize = haystack.size();
        bool eq = false;
        for (int i= 0;i<int(ssize)-int(needle.size())+1;i++){
            eq=true;
            for(int j =0;j < needle.size();j++){
                if(haystack[i+j]!=needle[j]){
                    eq=false;
                }
            }
            if(eq) return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution a= Solution();
    a.strStr("abb","abaaa");
    return 0;
}
