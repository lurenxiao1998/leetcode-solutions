class Solution {
public:
    int romanToInt(string s) {
        map<char,int> table={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        int lastnum=1000;
        char romanNum=' ';
        int res=0;
        for(int i=0;i<s.size();i++){
            romanNum=s[i];
            if(lastnum < table[ romanNum ])
                res-= lastnum*2;
            res+=table[romanNum];
            lastnum=table[romanNum];
        }
        return res;
    }
};