#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> readWord(string s){
        string word="";
        vector<string> res;
        for(int i=0;i<=s.size();i++){
            if(s[i]!=' ' && i!=s.size()){
                word.push_back(s[i]);
            }else{
                res.push_back(word);
                word="";
            }
        }
        return res;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string> words1 = readWord(sentence1);
        vector<string> words2 = readWord(sentence2);
        int i=0;
        if(words1.size()<words2.size()){
            swap(words1,words2);
        }
        
        for(;i<words2.size();i++){
            if(words2[i]!=words1[i]){
                break;
            }
        }
        cout<<i<<endl;
        for(;i<words2.size();i++){
            if(words2[i]!=words1[ words1.size() -i + words2.size() ]){
                break;
            }
        }
        return i==words2.size();
    }
};