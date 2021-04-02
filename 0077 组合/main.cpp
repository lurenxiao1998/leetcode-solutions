class Solution {
vector<vector<int>> res;
void recursion(vector<int> &path,int l,int k,int n){
    if(k==0)
        res.push_back(path);
    if(l+k-1>n)
        return;
    for(int i=l;i<=n;i++){
        path.push_back(i);
        recursion(path,i+1,k-1,n);
        path.pop_back();
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>path;
        recursion(path,1,k,n);
        return res;
    }
};