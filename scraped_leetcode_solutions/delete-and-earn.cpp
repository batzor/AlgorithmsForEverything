class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        vector<int> dp(largest + 1, 0);
        
        for(auto num: nums)
            dp[num] += num;
        
        for(int i = 2;i < largest + 1;++i){
            dp[i] = max(dp[i - 2] + dp[i], dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};