class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = nums.size() - k % nums.size();
        vector<int> tmp(nums.begin(), nums.begin() + k);
        nums.erase(nums.begin(), nums.begin() + k);
        nums.insert(nums.end(), tmp.begin(), tmp.end());
    }
};