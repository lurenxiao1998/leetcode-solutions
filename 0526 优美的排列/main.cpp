class Solution {
    vector<vector<int>> div;
    int res;
    set<int> path;
    void arrangement(int idx,int n) {
        if(idx == n){
            res ++;
            return;
        }
        for(auto &&it:div[idx]){
            auto itor = path.find(it);
            if(itor == path.end()){
                path.insert(it);
                arrangement(idx+1,n);
                path.erase(it);
            }
        }
    }
public:
    int countArrangement(int n) {
        res=0;
        for(int i =1;i<=n;i++){
            vector<int> tmp;
            for(int j=1;j<=n;j++){
                if( i%j==0 || j%i==0)
                    tmp.push_back(j);
            }
            div.push_back(tmp);
        }
        arrangement(0,n);
        return res;
    }
};