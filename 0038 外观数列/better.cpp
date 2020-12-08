#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++) {
            string temp;
            for(int j = 0; j < ans.length(); j++) {
                int cnt = 1;
                while( j+1 < ans.length() && ans[j] == ans[j+1]) {
                    cnt++;
                    j++;
                }
                auto a=cnt+'0';
                temp+=cnt+'0';
                temp+=ans[j];
            }
            ans = temp;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
  Solution().countAndSay(4);
  return 0;
}
