class Solution {
public:
    
    int fpwin[100001];
    bool winnerSquareGame(int n) {
        memset(fpwin, -1, sizeof(fpwin));
        for(int i = 1;i <= sqrt(n);++i){
            fpwin[i * i] = 1;
            fpwin[i * i + 2] = 1;
        }
        return dp(n, false);
    }
    
    bool dp(int n, bool bob_turn) {
        if(fpwin[n] != -1)
            return fpwin[n] ^ bob_turn;
        else{
            fpwin[n] = false;
            int sr = sqrt(n);
            for(int i = 1; i <= sr;++i){
                int tmp = i * i;
                dp(n - tmp, !bob_turn);
                if(!fpwin[n - tmp]){
                    fpwin[n] = true;
                    break;
                }
            }
            return fpwin[n] ^ bob_turn;
        }
    }
};