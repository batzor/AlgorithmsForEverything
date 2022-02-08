class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        while(start < nums.size()){
            if(nums[start] == 0)
                break;
            else
                ++start;
        }
        int n = nums.size();
        for(int i = start + 1;i < n;i++){
            if(nums[i] != 0 && start != i){
                nums[start] = nums[i];
                nums[i] = 0;
                ++start;
            }
        }
    }
};