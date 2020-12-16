#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void swap(int &a,int& b){
        a^=b;
        b^=a;
        a^=b;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=matrix.size();
        for (size_t i = 0; i < (matrix.size()-1)/2+1; i++)
        {
            for (size_t j = 0; j < matrix.size()/2; j++)
            {
                swap(matrix[i][j],matrix[l-j-1][i]);
                swap(matrix[i][j],matrix[l-1-i][l-1-j]);
                swap(matrix[i][j],matrix[j][l-1-i]);
            }
        }
        
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix= {{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotate(matrix);
    return 0;
}
