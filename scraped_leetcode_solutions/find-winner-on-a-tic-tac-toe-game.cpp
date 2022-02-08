class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int win[8] = {0};
        for(int i = 0;i < moves.size(); i+= 2){
            win[moves[i][0]]++;
            win[3 + moves[i][1]]++;
            if(moves[i][0] == moves[i][1])
                win[6]++;
            if(moves[i][0] == 2 - moves[i][1])
                win[7]++;
        }
        for(int i = 0;i < 8;++i){
            if(win[i] == 3) return "A";
        }
        
        memset(win, 0, sizeof(win));
        for(int i = 1;i < moves.size(); i+= 2){
            win[moves[i][0]]++;
            win[3 + moves[i][1]]++;
            if(moves[i][0] == moves[i][1])
                win[6]++;
            if(moves[i][0] == 2 - moves[i][1])
                win[7]++;
        }
        for(int i = 0;i < 8;++i){
            if(win[i] == 3) return "B";
        }
        
        if(moves.size() == 9)
            return "Draw";
        return "Pending";
    }
};