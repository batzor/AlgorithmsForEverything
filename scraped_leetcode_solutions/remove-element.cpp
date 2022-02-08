class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int m = nums.size();
        for(int i = 0;i < m;++i){
            if(nums[i] == val){
                nums[i] = nums[m - 1];
                i--;
                m--;
            }
        }
        return m;
    }
};