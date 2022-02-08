class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> ladder_usage;
        for(int i = 1;i < heights.size();++i){
            int prev = heights[i - 1];
            if(heights[i] <= prev)
                continue;
            else
                ladder_usage.push(prev - heights[i]);
            
            if(ladder_usage.size() > ladders){
                bricks += ladder_usage.top();
                if(bricks < 0) {
                    return i - 1;
                }
                ladder_usage.pop();
            }
        }
        return heights.size() - 1;
    }
};