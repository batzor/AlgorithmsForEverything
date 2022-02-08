class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        
        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));
        for(int size = 1; size <= N;++size){
            int alex = (N - size) % 2 + 1;
            for(int i = 0,j = size - 1;j < N;++i,++j){
                if(alex)
                    dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                else
                    dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                    
            }
        }
        return dp[1][N] > 0;
    }
};