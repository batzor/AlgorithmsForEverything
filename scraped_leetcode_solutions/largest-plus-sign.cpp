class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        bool grids[n][n];
        memset(grids, true, sizeof(grids));
        for(auto v: mines){
            grids[v[0]][v[1]] = false;
        }
        int max_size = 0;
        for(int i = 0; i < n;++i){
            for(int j = 0;j < n;++j){
                int size = 0;
                if(grids[i][j])
                    ++size;
                else
                    continue;
                
                int tmp = min(min(j, n - j - 1), min(i, n - i - 1));
                while(size <= tmp){
                    if(grids[i - size][j] && grids[i + size][j] && grids[i][j - size] && grids[i][j + size])
                        size++;
                    else
                        break;
                }
                max_size = max(max_size, size);
            }
        }
        return max_size;
    }
};