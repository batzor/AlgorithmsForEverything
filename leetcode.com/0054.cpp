#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<int> ret;
      for(int i = 0;i < (m + 1) / 2 && i < (n + 1) / 2;++i){
        for(int j = i;j < n - i;++j){
          ret.push_back(matrix[i][j]);
        }
        for(int j = i + 1;j < m - i;++j){
          ret.push_back(matrix[j][n - i - 1]);
        }
        if(i != m - i - 1)
          for(int j = n - i - 2;j >= i;--j){
            ret.push_back(matrix[m - i - 1][j]);
          }
        if(i != n - i - 1)
          for(int j = m - i - 2;j > i;--j){
            ret.push_back(matrix[j][i]);
          }
      }
      return ret;
    }
};

void solve() {
  Solution s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
