class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
      return 0;
    vector<int> dp(s.size(), 1);
    int n1, n2;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '0') {
        if (s[i - 1] == '1' || s[i - 1] == '2') {
          if (i > 1) {
            dp[i] = dp[i - 2];
            dp[i - 1] = dp[i - 2];
          } else {
            dp[i] = dp[i - 1];
          }
        } else {
          return 0;
        }
      } else {
        n1 = (s[i - 1] - '0') * 10 + s[i] - '0';
        if (n1 > 10 && n1 <= 26) {
          if (i == 1) {
            dp[i] = 2;
          } else {
            dp[i] = dp[i - 1] + dp[i - 2];
          }
        } else {
          dp[i] = dp[i - 1];
        }
      }
    }
    return dp[s.size() - 1];
  }
};