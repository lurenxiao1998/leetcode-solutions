#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int idx = 0;
    string wordmix = "";
    while (true) {
      if (idx >= word1.size()) {
        wordmix.append(word2.begin() + idx, word2.end());
        break;
      }

      if (idx >= word2.size()) {
        wordmix.append(word1.begin() + idx, word1.end());
        break;
      }
      wordmix.append(1, word1[idx]);
      wordmix.append(1, word2[idx]);
      idx += 1;
    }
    return wordmix;
  }
};
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
