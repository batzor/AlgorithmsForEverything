class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int ret = 2;
        for(int i = 2;i < nums.size();i++){
            if(nums[i] > nums[ret - 2])
                nums[ret++] = nums[i];
        }
        return ret;
    }
};