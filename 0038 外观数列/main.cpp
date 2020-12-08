#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string countAndSay(int n) {
    string str = "1";
    string newStr = "";
    int num = 1;
    for (size_t tern = 1; tern < n; tern++) {
      num = 1;
      for (size_t i = 0; i < str.size(); i++) {
        if (i == 0) {
          continue;
        }

        if (str[i] == str[i - 1]) {
          num += 1;
        } else {
          newStr += to_string(num) + str[i - 1];
          num = 1;
        }

      }
      newStr += to_string( num) + *(str.end()-1);
      str = newStr;
      newStr = "";
    }

    return str;
  }
};
int main(int argc, char const *argv[])
{
  Solution().countAndSay(4);
  return 0;
}
