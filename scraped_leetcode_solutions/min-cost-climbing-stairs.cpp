class Solution {
public:
    int mincost[1002] = {-1};
    int minCostClimbingStairs(vector<int>& cost) {
        mincost[0] = 0;
        mincost[1] = 0;
        mincost[2] = min(cost[0], cost[1]);
        for(int i = 3;i <= cost.size();i++){
            mincost[i] = min(mincost[i - 1] + cost[i - 1], mincost[i - 2] + cost[i - 2]);
        }
        return mincost[cost.size()];
    }
};