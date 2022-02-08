class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0;
        int step = 0;
        int prev_reach = -1;
        while(reach < nums.size() - 1){
            ++step;
            int new_reach = reach;
            for(int i = prev_reach + 1;i < nums.size() && i <= reach;++i)
                new_reach = max(nums[i] + i, new_reach);
            prev_reach = reach;
            reach = new_reach;
        }
        return step;
    }
};