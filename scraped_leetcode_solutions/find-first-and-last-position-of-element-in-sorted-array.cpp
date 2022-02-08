class Solution {
public:
    int binarySearch(vector<int> &nums, double target, int low, int high) {
        if(high <= low)
            return (target > nums[low]) ? (low + 1) : low;
 
        int mid = (low + high) / 2;
 
        if(target > nums[mid])
            return binarySearch(nums, target, mid + 1, high);
        return binarySearch(nums, target, low, mid - 1);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return vector<int>(2, -1);
        
        double lbound = (double) target - 0.5;
        double hbound = (double) target + 0.5;
        int start = binarySearch(nums, lbound, 0, nums.size() - 1);
        int end = binarySearch(nums, hbound, 0, nums.size() - 1);
        if(start > end - 1) {
            return vector<int>(2, -1);
        }
        return vector<int>{start, end - 1};
    }
};