#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int numDistinct(string s, string t) {
    vector<vector<int>> dp(t.size(), vector<int>(s.size(), 0));
    if(t=="")
      return 1;
    if(s=="")
      return 0;
    if (s[0] == t[0])
      dp[0][0] = 1;

    for (int j = 1; j < s.size(); j++) {
      if (s[j] == t[0])
        dp[0][j] = dp[0][j - 1] + 1;
      else
        dp[0][j] = dp[0][j-1];
    }

    for (int i = 1; i < t.size(); i++) {
      for (int j = i; j < s.size()-(t.size()-i-1); j++) {
        if (t[i] == s[j])
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
    return dp[t.size() - 1][s.size() - 1];
  }
};
int main(){
  Solution().numDistinct("babgbag","bag");
}