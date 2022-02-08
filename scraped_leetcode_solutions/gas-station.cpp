class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int cur = 0;
        int start = 0;
        for(int i = 0; i < gas.size();++i){
            int diff = gas[i] - cost[i];
            cur += diff;
            total += diff;
            if(cur < 0){
                cur = 0;
                start = i + 1;
            }
        }
        return total < 0 ? -1 : start;
    }
};