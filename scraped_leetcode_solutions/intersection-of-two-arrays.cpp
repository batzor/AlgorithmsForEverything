class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        nums1.erase(std::unique(nums1.begin(), nums1.end()),nums1.end());
        
        vector<int> ret;
        for(auto num: nums2){
            auto it = std::find(nums1.begin(),nums1.end(), num);
            if(it != nums1.end()){
                ret.push_back(*it);
                nums1.erase(it);       
            }
        }
        
        return ret;
    }
};