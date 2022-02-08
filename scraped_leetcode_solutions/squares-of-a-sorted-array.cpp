class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> vec1, vec2;
        int bound = std::upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        for(int i = bound;i < nums.size();++i)
            vec1.push_back(nums[i] * nums[i]);
        int m = vec1.size();
        for(int i = bound - 1;i >= 0;--i){
            vec1.push_back(0);
            vec2.push_back(nums[i] * nums[i]);
        }
        
        merge(vec1, m, vec2, vec2.size());
        return vec1;
    }
    
    inline void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp = nums1;
        nums1[0] = -1;
        int idx1 = 0, idx2 = 0;
        while(idx1 < m && idx2 < n){
            if(tmp[idx1] <= nums2[idx2]){
                nums1[idx1 + idx2] = tmp[idx1];
                idx1++;
            }else{
                nums1[idx1 + idx2] = nums2[idx2];
                idx2++;
            }
        }
        while(idx1 < m){
            nums1[idx1 + idx2] = tmp[idx1];
            idx1++;
        }
        while(idx2 < n){
            nums1[idx1 + idx2] = nums2[idx2];
            idx2++;
        }
    }
};