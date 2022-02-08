class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int step = (nums1.size() + nums2.size() + 1) / 2;
        if(nums1.size() == 0){
            if(nums2.size() % 2 == 1)
                return nums2[step - 1];
            else
                return ((float) nums2[step - 1] + nums2[step]) / 2;
        }
        
        if(nums2.size() == 0){
            if(nums1.size() % 2 == 1)
                return nums1[step - 1];
            else
                return ((float) nums1[step - 1] + nums1[step]) / 2;
        }
        
        int start1 = 0;
        int start2 = 0;
        int end1 = 0;
        int end2 = 0;

        while(step > 1){
            end1 = start1 + step / 2;
            end2 = start2 + step / 2;
            
            if(end1 > nums1.size())
                end1 = nums1.size();
            if(end2 > nums2.size())
                end2 = nums2.size();
         
            if(nums1[end1 - 1] < nums2[end2 - 1] && end1 != start1){
                step -= end1 - start1;
                start1 = end1;
            }else{
                step -= end2 - start2;
                start2 = end2;  
            }

            if(start1 == nums1.size()){
                start2 += step;
                step = 0;
                break;
            }
            if(start2 == nums2.size()){
                start1 += step;
                step = 0;
                break;
            }
        }
    
        if(step == 1){
            if(nums1[start1] < nums2[start2])
                start1++;
            else
                start2++;
        }
        
        int median1;
        if(start1 == 0)
            median1 = nums2[start2 - 1];
        else if(start2 == 0)
            median1 = nums1[start1 - 1];
        else
            median1 = max(nums1[start1 - 1], nums2[start2 - 1]);
        
        if((nums1.size() + nums2.size()) % 2 == 1)
            return median1;
        else{
            if(start1 == nums1.size())
                return ((float) median1 + nums2[start2]) / 2;
            if(start2 == nums2.size())
                return ((float) median1 + nums1[start1]) / 2;
            
            return ((float) median1 + min(nums1[start1], nums2[start2])) / 2;
        }
    }
};