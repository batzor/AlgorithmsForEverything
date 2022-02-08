class Solution {
public:
    int amt[101];
    int rob(vector<int>& nums) {
        amt[0] = 0;
        amt[1] = nums[0];
        for(int i = 2; i <= nums.size();++i){
            amt[i] = max(nums[i-1] + amt[i - 2], amt[i - 1]);
        }
        return amt[nums.size()];
    }
};