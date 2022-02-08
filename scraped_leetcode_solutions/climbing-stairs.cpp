class Solution {
public:
    int ans[46] = {-1};
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(ans[n] > 0)
            return ans[n];
        ans[n] = climbStairs(n - 2) + climbStairs(n - 1);
        return ans[n];
        
    }
};