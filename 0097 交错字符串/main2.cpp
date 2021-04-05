class Solution {
    vector<vector<int>> mem;
    bool dfs(int idxs1,string s1,int idxs2, string s2,int idxs3,string s3){
        if(idxs1==s1.size()&&idxs2==s2.size()&&idxs3==s3.size()){
            return true;
        }
        if(mem[idxs1][idxs2]!=-1){
            return mem[idxs1][idxs2];
        }
        int res=false;
        if( idxs1 < s1.size()&& idxs3<s3.size() && s1[idxs1] == s3[idxs3] ){
            res = res|dfs(idxs1+1,s1,idxs2,s2,idxs3+1,s3);
        }
        if(res){
            mem[idxs1][idxs2]=1;
            return res;
        }
        if( idxs2< s2.size() && idxs3<s3.size() && s2[idxs2] == s3[idxs3]){
            res = res|dfs(idxs1,s1,idxs2+1,s2,idxs3+1,s3);
        }
        mem[idxs1][idxs2]=res;
        return res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        mem=vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1));
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        return dfs(0,s1,0,s2,0,s3);
    }
};