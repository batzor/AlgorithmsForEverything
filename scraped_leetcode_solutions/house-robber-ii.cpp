class Solution {
public:
    int amt[101];
    inline int rob1(vector<int>& nums) {
        amt[0] = 0;
        amt[1] = nums[0];
        for(int i = 2; i <= nums.size();++i){
            amt[i] = max(nums[i-1] + amt[i - 2], amt[i - 1]);
        }
        return amt[nums.size()];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() < 3)
            return rob1(nums);
        int tmp = nums[0];
        nums[0] = 0;
        int res1 = rob1(nums);
        nums[0] = tmp;
        nums[nums.size() - 1] = 0;
        int res2 = rob1(nums);
        return max(res1, res2);
        
    }
};