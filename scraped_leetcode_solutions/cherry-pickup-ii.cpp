class Solution {
public:
    int mem[71][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(mem, -1, sizeof(mem));
        return dp(0, 0, grid[0].size() - 1, grid);
    }
    int dp(int r, int c1, int c2, vector<vector<int>> &grid){
        if(c1 < 0 || c1 > grid[0].size() - 1 || c2 < 0 || c2 > grid[0].size() - 1 || c1 == c2)
            return -1;
        if(mem[r][c1][c2] != -1)
            return mem[r][c1][c2];
        if(r == grid.size() - 1){
            mem[r][c1][c2] = grid[r][c1] + grid[r][c2];
            return mem[r][c1][c2];
        }
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1, c2, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1 - 1, c2, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1 + 1, c2, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1, c2 + 1, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1 - 1, c2 + 1, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1 + 1, c2 + 1, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1, c2 - 1, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1 - 1, c2 - 1, grid));
        mem[r][c1][c2] = max(mem[r][c1][c2], dp(r + 1, c1 + 1, c2 - 1, grid));
        mem[r][c1][c2] += grid[r][c1] + grid[r][c2];
        return mem[r][c1][c2];   
    }
};