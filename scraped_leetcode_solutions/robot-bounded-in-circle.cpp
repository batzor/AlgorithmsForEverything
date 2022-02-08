class Solution {
public:
    bool isRobotBounded(string instructions) {
        instructions = instructions + instructions + instructions + instructions;
        int up = 0;
        int right = 0;
        int dir = 0;
        for(int i = 0;i < instructions.length();++i){
            if(instructions[i] == 'G'){
                if(dir == 0)
                    ++up;
                if(dir == 1)
                    ++right;
                if(dir == 2)
                    --up;
                if(dir == 3)
                    --right;
            }
            else if(instructions[i] == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }
        return up == 0 && right == 0;
    }
};