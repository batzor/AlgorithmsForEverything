class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev_sum = nums[0];
        int max_sum = prev_sum;
        for(int i = 1;i < nums.size();++i){
            prev_sum = max(nums[i], prev_sum + nums[i]);
            max_sum = max(prev_sum, max_sum);
        }
        return max_sum;
    }
};