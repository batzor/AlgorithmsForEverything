class Solution {
public:
    bool canJump(vector<int>& nums, int startIdx = 0) {
        int reach = 0;
        for(int i = 0; i <= reach && reach < nums.size() - 1;++i)
            reach = max(i + nums[i], reach);
        return reach >= nums.size() - 1;
    }
};