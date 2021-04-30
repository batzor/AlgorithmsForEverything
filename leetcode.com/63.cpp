#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if(obstacleGrid.back().back() == 1)
        return 0;
      if(obstacleGrid[0][0] == 1)
        return 0;
      obstacleGrid[0][0] = -1;
      for(int i = 0;i < obstacleGrid.size();i++){
        for(int j = 0;j < obstacleGrid[0].size();j++){
          if(obstacleGrid[i][j] == 1)
            continue;
          if(i > 0){
            if(obstacleGrid[i - 1][j] != 1){
              obstacleGrid[i][j] += obstacleGrid[i - 1][j];
            }
          }
          if(j > 0){
            if(obstacleGrid[i][j - 1] != 1){
              obstacleGrid[i][j] += obstacleGrid[i][j - 1];
            }
          }
        }
      }
      return abs(obstacleGrid.back().back());
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
