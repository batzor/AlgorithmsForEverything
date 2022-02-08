class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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