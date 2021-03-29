class Solution {
    vector<string> res;
void genrecurision(string s,int lp,int rp){
    if(lp<=0 && rp<=0){
        res.push_back(s);
        return;
    }

    if(lp<rp ){
        if(lp>0)
            genrecurision(s+"(",lp-1,rp);
        genrecurision(s+")",lp,rp-1);
    }else{
        genrecurision(s+"(",lp-1,rp);
    }
}
public:
    vector<string> generateParenthesis(int n) {
        genrecurision("",n,n);
        return res;
    }
};