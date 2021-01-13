#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> r{first};
        int n=first;
        for (size_t i = 0; i < encoded.size(); i++)
        {
            r.push_back(encoded[i] ^ n);
            n = encoded[i] ^ n;
        }
        return r;
    }
};