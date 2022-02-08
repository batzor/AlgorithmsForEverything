class Solution {
public:
    void flood(int x, int y, vector<vector<int>> &obstacleGrid) {
        if(x + 1 < obstacleGrid.size()){
            if(obstacleGrid[x+1][y] <= 0) {
                obstacleGrid[x+1][y]--;
                flood(x+1, y, obstacleGrid);
            }
        }
        if(y + 1 < obstacleGrid[0].size()){
            if(obstacleGrid[x][y + 1] <= 0) {
                obstacleGrid[x][y+1]--;
                flood(x,y+1,obstacleGrid);
            }
        }
    }
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