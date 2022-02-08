class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxleft = height[left];
        int maxright = height[right];
        
        int ans = 0;
        while(left != right){
            if(maxleft <= maxright){
                left++;
                if(maxleft >= height[left])
                    ans += maxleft - height[left];
                else
                    maxleft = height[left];
            }else{
                right--;
                if(maxright >= height[right])
                    ans += maxright - height[right];
                else
                    maxright = height[right];
            }
        }
        return ans;
    }
};