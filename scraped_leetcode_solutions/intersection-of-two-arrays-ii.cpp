class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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