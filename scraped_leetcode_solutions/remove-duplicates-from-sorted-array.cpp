class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int it = std::unique(nums.begin(), nums.end()) - nums.begin();
        return it;
    }
};