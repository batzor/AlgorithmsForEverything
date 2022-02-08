class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int *dp = new int[2001];
        memset(dp, 0, 2001 * sizeof(int));
        dp[nums[0] + 1000] = 1;
        dp[-nums[0] + 1000] += 1;      // +1 to cover the case when nums[0] == 0
        for(int i = 1; i <  nums.size();i++){
            int *dp1 = new int[2001];
            memset(dp1, 0, 2001 * sizeof(int));
            for(int sum = 0; sum < 2001; sum++){
                if(dp[sum] > 0){
                    if(sum + nums[i] < 2001 && sum + nums[i] >= 0){
                        dp1[sum + nums[i]] += dp[sum];   
                    }
                    if(sum - nums[i] < 2001 && sum - nums[i] >= 0){
                        dp1[sum - nums[i]] += dp[sum];
                    }
                }
            }
            dp = dp1;
        }
        return S > 1000 ? 0 : dp[S + 1000];
    }
};