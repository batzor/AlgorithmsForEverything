class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

            int ret = nums[0] + nums[1] + nums[2];
            for(int i = 0;i < nums.size();i++){
                int l = i + 1;
                int r = nums.size() - 1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(abs(target - sum) <  abs(target - ret))
                        ret = sum;
                    if(target < sum)
                        --r;
                    if(target > sum)
                        ++l;
                    if(target == sum)
                        return sum;
                }
            }
            
            return ret;

    }
};